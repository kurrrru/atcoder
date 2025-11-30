for problem in {A..G}; do
    cd ${problem}
    oj d https://atcoder.jp/contests/abc426/tasks/abc426_${problem}
    cd ..
done