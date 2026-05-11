for i in {1..8}
do
  echo $i | ./main > output.txt
  cat output.txt
  if grep -q "FAIL" output.txt; then
    echo "Test $i failed."
    exit 1
  fi
done
