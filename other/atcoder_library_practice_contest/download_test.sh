for dirname in {A..L}; do
    cd $dirname
    oj d https://atcoder.jp/contests/practice2/tasks/practice2_$dirname
    cd ..
done
