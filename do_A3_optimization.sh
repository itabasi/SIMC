mv infiles/A3_4300_MeV/3He_cen_1mC_rad_benhar_cont.data infiles/current.data
./simc << EOF
current.data
EOF
python python/make_root_one_default.py
mv output/current.root output/3He_cen_1mC_rad_benhar_cont.root
# ------------------------------------
mv infiles/A3_4300_MeV/3He_cen_1mC_rad_benhar_bound.data infiles/current.data
./simc << EOF
current.data
EOF
python python/make_root_one_default.py
mv output/current.root output/3He_cen_1mC_rad_benhar_bound.root
# ------------------------------------
mv infiles/A3_4300_MeV/3H_cen_1mC_rad_benhar_cont.data infiles/current.data
./simc << EOF
current.data
EOF
python python/make_root_one_default.py
mv output/current.root output/3H_cen_1mC_rad_benhar_cont.root
# ------------------------------------
mv infiles/A3_4300_MeV/2H_cen_1mC_rad.data infiles/current.data
./simc << EOF
current.data
EOF
python python/make_root_one_default.py
mv output/current.root output/2H_cen_1mC_rad.root
# ------------------------------------
mv infiles/A3_4300_MeV/3He_cen_1mC_rad_kaptari_cont.data infiles/current.data
./simc << EOF
current.data
EOF
python python/make_root_one_default.py
mv output/current.root output/3He_cen_1mC_rad_kaptari_cont.root
# ------------------------------------
mv infiles/A3_4300_MeV/3He_cen_1mC_rad_kaptari_bound.data infiles/current.data
./simc << EOF
current.data
EOF
python python/make_root_one_default.py
mv output/current.root output/3He_cen_1mC_rad_kaptari_bound.root
# ------------------------------------
mv infiles/A3_4300_MeV/3H_cen_1mC_rad_kaptari_cont.data infiles/current.data
./simc << EOF
current.data
EOF
python python/make_root_one_default.py
mv output/current.root output/3H_cen_1mC_rad_kaptari_cont.root
# ------------------------------------
