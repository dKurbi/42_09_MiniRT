if [ $# -ge 2  ]
then
	echo "noooo";
	exit 1;
elif [ $# -eq 0 ]
then
	valgrind --leak-check=full --track-fds=yes --trace-children=yes ./minirt files_rt/cylinder.rt
else
	valgrind --leak-check=full --track-fds=yes --trace-children=yes ./minirt $1
fi
