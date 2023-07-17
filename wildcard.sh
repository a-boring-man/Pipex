export FILE=`find source -name "*.c" | sed 's#.*/##g' | tr '\n' ' '`
sed -i "" "s#LST_SRC :=.*#LST_SRC := $FILE#g" Makefile
export FILE=`find source_bonus -name "*_bonus.c" | sed 's#.*/##g' | tr '\n' ' '`
sed -i "" "s#LST_SRC_BNS :=.*#LST_SRC_BNS := $FILE#g" Makefile