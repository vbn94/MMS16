
moreinfo.data: infofile.data
	cat infofile.data > moreinfo.data
	echo "More info" >> moreinfo.data

infofile.data:
	echo "Some info" > infofile.data

allinfo: moreinfo.data
	cat moreinfo.data > allinfo
	echo "all" >> allinfo

.PHONY: clear
clear:
	rm -f *.data allinfo