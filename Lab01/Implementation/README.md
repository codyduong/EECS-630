These files are generated from my implementation, not provided.

Created a script to help out running `./Lab1`
```sh
./test.sh
```

```
/usr/bin/time -v -o Implementation/log_1.txt ./Lab1 Inputs/input_1.txt > ./Implementation/output_1.txt

python3 GradingScript.py Implementation/output_1.txt Outputs/output_1.txt Implementation/log_1.txt Logs/log_1.txt 3600
```