    string exp_completa(string expr) {
        string expressio,definitiva;
        expressio = expr;
        definitiva ="";
        int count = 1;
        bool primer = true;
        while(count != 0) {
            if(primer) {
                for(int i = 1; i < expressio.length(); ++i) {
                    if(expressio[i] == '(') ++count;
                    if(expressio[i] == ')') --count;
                }
                primer = false;
            }
            else {
                for(int i = 0; i < expressio.length(); ++i) {
                    if(expressio[i] == '(') ++count;
                    if(expressio[i] == ')') --count;
                }
            }
            definitiva += expressio;
            if(count != 0) getline(cin,expressio);
        }
        return definitiva;
    }    
    
    string fill_complet(string au) {
        string aux = au;
        string fill = "";
        int count = 1;
        bool primer = true;
        while(count != 0) {
            if(primer) {
                for(int i = 1; i < aux.length(); ++i) {
                    if(aux[i] == '(') ++count;
                    if(aux[i] == ')') --count;
                }
                primer = false;
            }
            else {
                for(int i = 0; i < aux.length(); ++i) {
                    if(aux[i] == '(') ++count;
                    if(aux[i] == ')') --count;
                }
            }
            fill += aux;
            if(count != 0) iss >> aux;
        }
        return fill;
    }
