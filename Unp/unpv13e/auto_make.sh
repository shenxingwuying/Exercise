./configure
cd lib
make
cd ../libfree
make
cd ../libroute
make
cd ../libxti
make
cd ../intro
make daytimetcpcli
./daytimetcpcli 127.0.0.1
