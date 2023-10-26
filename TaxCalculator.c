#include <stdio.h>

int main() {

    // Rerun calculations with do while loop
    int restartValidation;
    do {
    
    double grossIncome;
    int taxBrackets[] = {11000, 44725, 95375, 182100, 231250, 578125};
    double taxRates[] = {0.10, 0.12, 0.22, 0.24, 0.32, 0.35, 0.37}; 
    int numBrackets = sizeof(taxRates) / sizeof(taxRates[0]);
    double flatTaxRate = 0.123; // Flat 4.95% State tax + 7.65% FICA tax

    printf("\nEnter your gross income: $");
    scanf("%lf", &grossIncome);
    double initialIncome = grossIncome;
    double flatTax = grossIncome * flatTaxRate;

    grossIncome -= flatTax;
    double marginalTax = 0.0;

    // Calculate the total tax by iterating through brackets until there is no more taxable income. 
    for (int i = 0; i < numBrackets; i++) {
        if (grossIncome <= 0) {
            break; // No more income to tax
        }

        // Calculates income that falls within the current tax bracket
        double bracketIncome = grossIncome < taxBrackets[i] ? grossIncome : taxBrackets[i];
        double bracketTax = bracketIncome * taxRates[i];

        marginalTax += bracketTax; // Counter for the total amount of income taxed marginally
        grossIncome -= bracketIncome; // Counter for remaining untaxed income
    }

    // Calculate the effective tax rate
    double totalTaxes = marginalTax + flatTax;
    double effectiveTaxRate = (totalTaxes / initialIncome) * 100;
    double takeHomePay = initialIncome - totalTaxes;

    printf("\nFlat tax paid: $%.2lf\n", flatTax);
    printf("Marginal tax paid: $%.2lf\n", marginalTax);
    printf("Total taxes: $%.2lf\n", totalTaxes);
    printf("Take home pay: $%.2lf\n", takeHomePay);
    printf("Effective tax rate: %.2lf percent.\n\n", effectiveTaxRate);


    //Restart do while loop and verify user input as either 1 or 0
    printf("Enter 1 to restart, enter any other key to quit: ");
    } while (scanf("%d", &restartValidation) == 1 && restartValidation == 1);

        
    return 0;
}


