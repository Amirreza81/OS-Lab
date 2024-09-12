#!bin/bash

echo "pocess info for pid $1"

process_name=$(awk '{print $2}' /proc/$1/stat)
echo "pocess name : $process_name"

process_status=$(awk '{print $3}' /proc/$1/stat)
echo "pocess status: $process_status"

memory_usage=$(awk '{print $24}' /proc/$1/stat)
echo "memory usage : $memory_usage pages"

uid=$(awk '{print $8}' /proc/$1/stat)
gid=$(awk '{print $9}' /proc/$1/stat)
echo "user id: $uid, group id: $gid"

thread_number=$(awk '{print$20}' /proc/$1/stat)
echo "number of threads : $thread_number"

command_line=$(tr '\0' ' ' < /proc/$1/cmdline)
echo "Command line: $command_line"