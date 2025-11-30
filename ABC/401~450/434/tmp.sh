for problem in {A..G}; do
    cd ${problem}
    oj d https://atcoder.jp/contests/abc434/tasks/abc434_${problem}
    cd ..
done