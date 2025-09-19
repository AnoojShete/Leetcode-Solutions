class Spreadsheet {
public:
    unordered_map<string, int> mpp;
    Spreadsheet(int rows) {
        ;
    }
    
    void setCell(string cell, int value) {
        mpp[cell] = value;
    }
    
    void resetCell(string cell) {
        setCell(cell, 0);
    }
    
    int getValue(string formula) {
        for(int i = 1; i < formula.length(); ++i) {
            if(formula[i] == '+') {
                string cell1 = formula.substr(1, i-1);
                string cell2 = formula.substr(i+1);
                int val1 = isalpha(cell1[0]) ? mpp[cell1] : stoi(cell1);
                int val2 = isalpha(cell2[0]) ? mpp[cell2] : stoi(cell2);
                return val1 + val2;
            }
        }
        return 0;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */