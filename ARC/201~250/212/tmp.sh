for problem in {A..E}; do
    cd ${problem}
    oj d https://atcoder.jp/contests/arc212/tasks/arc212_${problem}
    cd ..
done