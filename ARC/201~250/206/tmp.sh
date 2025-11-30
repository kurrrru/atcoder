for problem in {A..E}; do
    cd ${problem}
    oj d https://atcoder.jp/contests/arc206/tasks/arc206_${problem}
    cd ..
done