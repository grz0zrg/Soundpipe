#!/bin/sh

mkdir -p docs
cp -r util/css docs

> docs/modules.txt

for d in modules/data/*.lua
do
    module=$(basename ${d%.*})
    echo "writing $module"
    util/data2html.lua $module > docs/$module.html
    echo $module >> docs/modules.txt
done

util/gen_index.lua docs/modules.txt > docs/index.html
