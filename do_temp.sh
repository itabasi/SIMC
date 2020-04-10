mv infiles/Tritium/1H_mid_1mC_rad.data.less infiles/current.data
./simc << EOF
current.data
EOF
python python/make_root_one_default.py
mv output/current.root output/1H_mid_1mC_rad.data.root.less
# -------------------------------------------------
mv infiles/Tritium/1H_mid_1mC_rad.data infiles/current.data
./simc << EOF
current.data
EOF
python python/make_root_one_default.py
mv output/current.root output/1H_mid_1mC_rad.data.root
