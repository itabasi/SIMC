mv infiles/Tritium/3He_fast_1mC_noRad_kaptari_bound.data infiles/current.data
./simc << EOF
current.data
EOF
python python/make_root_one_default.py
mv output/current.root output/3He_fast_1mC_noRad_kaptari_bound.root
# ----------------
mv infiles/Tritium/3He_fast_1mC_noRad_kaptari_cont.data infiles/current.data
./simc << EOF
current.data
EOF
python python/make_root_one_default.py
mv output/current.root output/3He_fast_1mC_noRad_kaptari_cont.root
# ----------------
mv infiles/Tritium/3H_fast_1mC_noRad_kaptari_cont.data infiles/current.data
./simc << EOF
current.data
EOF
python python/make_root_one_default.py
mv output/current.root output/3H_fast_1mC_noRad_kaptari_cont.root
