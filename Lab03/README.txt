1) Ten instances are included.
      input_[1-10].txt:         the input file;
      output_[1-10].txt:        the correct output file;
      log_[1-10].txt:           the log file of expected running time and consume memory.

2) Compile MainTest to test data files:
      `g++ -std=c++11 MainTest.cpp -o Lab4`

3) You are encouraged to check time, memory:
      /usr/bin/time -v -o ${LOG_FILE} ./Lab4 ${input_[1-10].txt} > ${result_[1-10].txt}

4) Comparing your result with expected output:
      python3 GradingScript.py ${result_[1-10].txt} ${output_[1-10].txt} ${YOUR_LOG_FILE} ${log_[1-10].txt} ${YOU_CPU_CLOCK_RATE}

   * You can use `cat /proc/cpuinfo | grep 'MHz'` to find out your CPU clock rate in MHz.
     In case you have multiple cores with different rates, please input the largest value.
   * You should see 3 lines messages, the first line tells if your program generates
     the expected output, the second line tells if your program runs within a proper
     amount of time, and the third line tells if your program uses a proper amount of space.
     For a completely correct run, you should see three "Yes" from the output.
   * Keep an eye on the standard output, you need to have diff program on your system.
