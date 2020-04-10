mv infiles/Tritium/2H_fast_1mC_rad.data infiles/current.data
./simc << EOF
current.data
EOF
python python/make_root_one_default.py
mv output/current.root output/2H_fast_1mC_rad.root
# ----------------
