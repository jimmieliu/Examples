echo "======= Step1 copy Python.h of your PC using commands below:"
# path=`find / -name Python.h 2>/dev/null | grep include | grep 3 | head -1`
# files=${path/Python.h/}'*.h'
# cp $files header/

echo "======= Step2 build the c++ code"
rm -rf ./build
python3 setup.py build

echo "======= Step3 rename the lib"
sopath=`find build/ -name *.so`
rm -rf ./demo.so
mv $sopath ./demo.so

echo "====== Step4 run the test"
python3 test.py

