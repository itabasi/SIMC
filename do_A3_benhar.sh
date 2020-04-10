mv infiles/Tritium/3He_slow_1mC_rad_benhar_bound.data infiles/current.data
./simc << EOF
current.data
EOF
python python/make_root_one_default.py
mv output/current.root output/3He_slow_1mC_rad_benhar_bound.root
# ----------------
mv infiles/Tritium/3He_slow_1mC_rad_benhar_cont.data infiles/current.data
./simc << EOF
current.data
EOF
python python/make_root_one_default.py
mv output/current.root output/3He_slow_1mC_rad_benhar_cont.root
# ----------------
mv infiles/Tritium/3H_slow_1mC_rad_benhar_cont.data infiles/current.data
./simc << EOF
current.data
EOF
python python/make_root_one_default.py
mv output/current.root output/3H_slow_1mC_rad_benhar_cont.root
