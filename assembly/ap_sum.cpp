int findNthTermOfAP(int firstTerm, int commonDifference, int n) {
    int nthTerm = firstTerm;
    for (int i = 1; i < n; i++) {
        nthTerm += commonDifference;
    }
    return nthTerm;
}