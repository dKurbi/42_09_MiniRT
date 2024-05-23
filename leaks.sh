if [ $# -ge 2  ]
then
	echo "noooo";
	exit 1;
elif [ $# -eq 0 ]
then
	leaks --atExit -- ./minirt files_rt/scene.rt
else
	leaks --atExit -- ./minirt $1
fi
