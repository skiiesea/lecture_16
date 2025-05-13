#!/bin/bash

service=$1;
s=$2;
v=$3;
vv=$4;

invalidArgs () {
	echo "ERROR! Use this syntax: ./service_control <SERVICE_NAME> [OPTION] [OPTION]";
	exit;
}

if [ "$service" = "" ]; then
	invalidArgs;
else
	if [ "$s" = "-s" ]; then

		if [ "$v" = "" ]; then
			invalidArgs;
		else
			action=$v;

			if [ "$vv" = "-v" ]; then
				more_info=true;
			fi;
		fi;


	elif [ "$s" = "-v" ]; then
		more_info=true;

		if [ "$v" = "-s" ]; then
                	if [ "$vv" = "" ]; then
                        	invalidArgs;
                	else
                        	action=$vv;
                	fi;
		fi;
	else
		narg=true;
	fi;
fi;

if !(systemctl is-active ${service}); then
	sudo systemctl restart ${service};
	echo "${service} restarted!";
fi;

if [ $action ]; then

	sudo systemctl ${action} ${service};
	echo "Action: ${action} for service: ${service} applied"
fi;
