#!/bin/bash

mode=""
service=""
target=""
recursive=false
detail=false

while [[ $# -gt 0 ]]; do
	case "$1" in
		--service)
			mode="service"
			service="$2"
			shift 2
			;;
		--count-lines)
			mode="line_counter"
			target="$2"
			shift 2
			;;
		-r)
			recursive=true
			shift
			;;
		--detail)
			detail=true
			shift
			;;
		*)
			echo "Unknown argument: $1"
			exit 1
			;;
	esac
done

if [ "$mode" = "service" ]; then
	if [ -z "$service" ]; then
		echo "Usage: $0 --service <service_name>"
		exit 1
	fi
	
	if systemctl is-active --quiet "$service"; then
		echo "Service $service is running." 
	else
		echo "Service $service in not running. Attempting to restart.."
		
		if systemctl is-active --quiet "$service"; then
			echo "Service $service successfully restarted."
		else
			echo "Failed to restart $service"
			exit 1
		fi
	fi
elif [ "$mode" = "line_counter" ]; then
	if [ -z "$target" ]; then
		echo "Usage: $0 --count-lines <file_or_directory> [-r] [--detail]"
		exit 1
	fi

	count_lines() {
		local file="$1"
		local lines=$(wc -l < "$file" 2>/dev/null)
		if [ "$?" -ne 0 ]; then
			echo "Error reading file: $file" >&2
			return 1
		fi
		echo "$lines"
	}
	
	process_directory() {
		local dir="$1"
		local total=0
		local file_count=0

		while IFS= read -r -d '' file; do
			if [ -f "$file" ]; then
				lines=$(count_lines "$file")
				if [ "$?" -eq 0 ]; then
					total=$((total + lines))
					file_count=$((file_count + 1))
					if [ "$detail" = true ]; then
						echo "$file: $lines lines"
					fi
				fi
			fi
		done < <(find "$dir" -type f -print0 2>/dev/null)
		echo "Found $total lines in $file_count file(s)"
	}

	process_file() {
		if [ -f "$target" ]; then
			lines=$(count_lines "$target")
			if [ "$?" -eq 0 ]; then
				echo "$target: $lines lines"
				echo "Found $lines lines in 1 file(s)"
			else
				exit 1
			fi
		else
			echo "Error: '$target' is not a valid file"
			exit 1
		fi
	}
	if [ -d "$target" ]; then
		if [ "$recursive" = true ]; then
			process_directory "$target"
		else
			echo "Error: '$target' is a directory. Use -r for recursive counting."
			exit 1
		fi
	elif [ -f "$target" ]; then
		process_file "$target"
	else
		echo "Error: '$target' does not exist or is invalid."
		exit 1
	fi
else
	echo "Usage:"
	echo " Service control: $0 --service <service_name>"
	echo " Line counting: $0 --count-lines <file_or_dir> [-r] [--detail]"
	exit 1
fi

