#!/bin/bash
if [ $? -ne 1 ]; then
	echo "Use: $0 <service_name>"
	exit 1
fi

service_name="$1"

if [ $? -ne 0 ]; then
	echo "Service '$service_name' is not working. Reloading..."
	if [ $? -eq 0 ]; then
		echo "Service '$service_name' has been successfully launched"
	else
		echo "Coudn't restart the service '$service_name'"
	fi
else
	echo "Service '$service_name' is working"
fi

count_lines(){
	local path="$1"
	local total_lines=0
	local total_files=0

	if [ -d "$path" ]; then
		find "$path" -type f | while read -r file; do
		if [ "$detail" = true ]; then
			lines_in_file=$(wc -l < "$file")
			echo "$lines_in_file $file"
		fi
		total_lines=$((total_lines + $(wc -l < "$file")))
		total_files=$((total_files + 1))
	done
	elif [ -f  "$path" ]; then
		if [ "$detail" = true ]; then
			lines_in_file=$(wc -l < "$path")
			echo "$lines_in_file $path"
		fi
		total_lines=$((total_lines + $(wc -l < "$path")))
		total_files=1
	else
		echo "Specified path is unavailable: $path"
		exit 1
	fi

	echo "Found $total_lines lines in $total_files file(s)"
}

detail=false
recursive=false
target_path="$1"

shift

while [ $# -gt 0 ]; do
	case "$1" in
		-r)
			recursive=true
			;;
		-detail)
			detail=true
			;;
		*)
			;;
	esac
	shift
done

if [ "$recursive" = true ] && [ -d "$target_path" ]; then
	count_lines "$target_path"
elif [ "$recursive" = false ]; then
	count_lines "$target_path"
else
	echo "Functr -r required for counting recursively over a directory."
	exit 1
fi

