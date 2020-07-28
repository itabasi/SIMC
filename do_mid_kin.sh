mv infiles/Tritium/3He_mid_1mC_rad_kaptari_cont.data infiles/current.data
./simc << EOF
current.data
EOF
python python/make_root_one_default.py
mv output/current.root output/3He_mid_1mC_rad_kaptari_cont.root
# ----------------
mv infiles/Tritium/3He_mid_1mC_rad_kaptari_bound.data infiles/current.data
./simc << EOF
current.data
EOF
python python/make_root_one_default.py
mv output/current.root output/3He_mid_1mC_rad_kaptari_bound.root
# ----------------
mv infiles/Tritium/3H_mid_1mC_rad_kaptari_cont.data infiles/current.data
./simc << EOF
current.data
EOF
python python/make_root_one_default.py
mv output/current.root output/3H_mid_1mC_rad_kaptari_cont.root
# ----------------
mv infiles/Tritium/3He_mid_1mC_rad_benhar_cont.data infiles/current.data
./simc << EOF
current.data
EOF
python python/make_root_one_default.py
mv output/current.root output/3He_mid_1mC_rad_benhar_cont.root
# ----------------
mv infiles/Tritium/3He_mid_1mC_rad_benhar_bound.data infiles/current.data
./simc << EOF
current.data
EOF
python python/make_root_one_default.py
mv output/current.root output/3He_mid_1mC_rad_benhar_bound.root
# ----------------
mv infiles/Tritium/3H_mid_1mC_rad_benhar_cont.data infiles/current.data
./simc << EOF
current.data
EOF
python python/make_root_one_default.py
mv output/current.root output/3H_mid_1mC_rad_benhar_cont.root
# ----------------
