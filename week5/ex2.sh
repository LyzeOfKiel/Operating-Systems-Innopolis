if [[ ! -f "input.txt" ]]; then
    echo "1" > "input.txt"
fi

while true; do
    if ln "input.txt" "input.lock" 2> /dev/null ; then
        n=$(cat "input.txt" | tail -n 1)
        echo "$((n + 1))" >> input.txt
        rm "input.lock"
    fi
done