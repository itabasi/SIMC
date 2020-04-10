mv infiles/Tritium/3He_fast_1mC_rad_kaptari_bound.data infiles/current.data
./simc << EOF
current.data
EOF
python python/make_root_one_default.py
mv output/current.root output/3He_fast_1mC_rad_kaptari_bound.root
# ----------------
