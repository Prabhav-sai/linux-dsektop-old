clear
echo
#read -p "Enter the City Name:" cityname
echo "Computer:" $HOSTNAME >> $HOSTNAME"_astats.txt"
#echo "City:" $cityname
echo "Linux Kernel info:" `uname -a` >> $HOSTNAME"_astats.txt"
echo "Shell version:" $BASH_VERSION >> $HOSTNAME"_astats.txt"
clear
echo
echo $HOSTNAME"_stats.txt file written successfully."
echo
