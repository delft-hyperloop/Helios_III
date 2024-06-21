#!/usr/bin/bash

ip link add dev can0 type vcan
ip link set up can0

ip link add dev can1 type vcan
ip link set up can1
