#!/bin/bash

counter='0'
while IFS= read -r line; do
  echo "tester $counter: $line"
  counter= `expr $counter + 1`;
done < "bad-sector.txt"
