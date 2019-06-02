#!/bin/bash

# This script gonna download the yolo model to run the C++ programm
# To get the rights ==> (sudo) chmod +x dl.sh

mkdir model
cd model
mkdir yolo
cd yolo 

# Download the model

wget https://pjreddie.com/media/files/yolov3.weights
wget https://github.com/pjreddie/darknet/blob/master/cfg/yolov3.cfg?raw=true -O ./yolov3.cfg
wget https://github.com/pjreddie/darknet/blob/master/data/coco.names?raw=true -O ./coco.names