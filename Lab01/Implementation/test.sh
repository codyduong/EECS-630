#!/bin/bash

(
  cd "$(dirname "$0")"/..

  # Default upper bound
  upper_bound=10

  # If an argument is provided, use it as the upper bound
  if [ $# -eq 1 ]; then
    upper_bound=$1
  fi

  # Extract the highest CPU frequency
  highest_cpu_freq=$(cat /proc/cpuinfo | grep 'MHz' | awk '{print $4}' | sort -nr | head -n 1)

  echo "Found CPU frequency: $highest_cpu_freq MHz"

  # Loop from 1 to the upper bound
  for i in $(seq 10 $upper_bound); do
    echo "Running test for input $i..."
    
    # Run the time command and log the output
    /usr/bin/time -v -o Implementation/log_$i.txt ./Lab1 Inputs/input_$i.txt > Implementation/output_$i.txt

    # Check if the previous command was successful before continuing
    if [ $? -eq 0 ]; then
      # Run the grading script
      python3 GradingScript.py Implementation/output_$i.txt Outputs/output_$i.txt Implementation/log_$i.txt Logs/log_$i.txt $highest_cpu_freq
    else
      echo "Execution failed for input $i, skipping grading..."
    fi
  done

  echo "All tests completed."
)
