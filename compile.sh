#!/bin/bash

dir=`dirname $0`
glslc $dir/shaders/shader.vert -o $dir/shaders/vert.spv
glslc $dir/shaders/shader.frag -o $dir/shaders/frag.spv