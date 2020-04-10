mv infiles/Tritium/3He_fast_1mC_rad_kaptari_cont_inclusive.data infiles/current.data
./simc << EOF
current.data
EOF
python python/make_root_one_default.py
mv output/current.root output/3He_fast_1mC_rad_kaptari_cont_inclusive.root
# ----------------
mv infiles/Tritium/3He_fast_1mC_rad_kaptari_bound_inclusive.data infiles/current.data
./simc << EOF
current.data
EOF
python python/make_root_one_default.py
mv output/current.root output/3He_fast_1mC_rad_kaptari_bound_inclusive.root
# ----------------
mv infiles/Tritium/3H_fast_1mC_rad_kaptari_cont_inclusive.data infiles/current.data
./simc << EOF
current.data
EOF
python python/make_root_one_default.py
mv output/current.root output/3H_fast_1mC_rad_kaptari_cont_inclusive.root
# ----------------
mv infiles/Tritium/3He_slow_1mC_rad_kaptari_bound_inclusive.data infiles/current.data
./simc << EOF
current.data
EOF
python python/make_root_one_default.py
mv output/current.root output/3He_slow_1mC_rad_kaptari_bound_inclusive.root
# ----------------
mv infiles/Tritium/3He_slow_1mC_rad_kaptari_cont_inclusive.data infiles/current.data
./simc << EOF
current.data
EOF
python python/make_root_one_default.py
mv output/current.root output/3He_slow_1mC_rad_kaptari_cont_inclusive.root
# ----------------
mv infiles/Tritium/3H_slow_1mC_rad_kaptari_cont_inclusive.data infiles/current.data
./simc << EOF
current.data
EOF
python python/make_root_one_default.py
mv output/current.root output/3H_slow_1mC_rad_kaptari_cont_inclusive.
