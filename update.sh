echo -ne "Commit Data:"
read commit_data
git add .
git commit -m $commit_data
git push origin master
