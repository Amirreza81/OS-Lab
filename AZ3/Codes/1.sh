for pid in /proc/[0-9]*; do
    if [ -d "$pid" ] ; then
        pid_number = $(basename "$pid")

        if [ -f "$pid/comm" ]; then
            name = $(cat "$pid/comm")
            echo "PID: $pid_number Name: $name"
        fi
    fi
done