#!/bin/sh

ifconfig | grep ether | cut -c8- | cut -d ' ' -f1
