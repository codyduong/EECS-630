import os
import sys
time_factor = 4
space_factor = 4
default_freq = 2605.133

def searchLog(ff):
    CPU, time, space = 100, 999999999, 999999999
    with open(ff, 'r') as fin:
        for l in fin:
            l = l.strip()
            if l.find("Percent of CPU this job got:") > -1:
                CPU = float(l[l.rfind(":")+1:].replace("%",""))/100
            elif l.find("User time (seconds):") > -1:
                time = float(l[l.rfind(":")+1:])
            elif l.find("Maximum resident set size (kbytes)") > -1:
                space = float(l[l.rfind(":")+1:])
    time *= CPU
    return (time, space)

if __name__ == '__main__':
    f1 = sys.argv[1]
    f2 = sys.argv[2]
    f3 = sys.argv[3]
    f4 = sys.argv[4]
    user_freq = float(sys.argv[5])
    res_file = "test_result"
    cmd = "diff " + str(f1) + " " + str(f2) + " >" + res_file
    os.system(cmd)
    messagas = ["","",""]
    if os.path.exists(res_file) and os.stat(res_file).st_size == 0:
        messagas[0] = "Yes"
    else:
        messagas[0] = "No"

    default_time, default_space = searchLog(f4)
    user_time, user_sapce = searchLog(f3)
    scaled_user_time = user_time * user_freq / default_freq

    if scaled_user_time <= time_factor*default_time:
        messagas[1] = "Yes"
    else:
        messagas[1] = "No"

    if user_sapce <= space_factor*default_space:
        messagas[2] = "Yes"
    else:
        messagas[2] = "No"

    print("\n".join(messagas))
