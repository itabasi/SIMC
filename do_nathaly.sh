cp infiles/nathaly/current_helium.data infiles/current.data
./simc << EOF
current.data
EOF
python python/make_root_one_default.py
mv output/current.root output/current_helium.root
# ------------------------------------
cp infiles/nathaly/current_tritium.data infiles/current.data
./simc << EOF
current.data
EOF
python python/make_root_one_default.py
mv output/current.root output/current_tritium.root
# ------------------------------------
