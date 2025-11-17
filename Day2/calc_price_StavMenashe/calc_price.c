/*------------------------------------------------------
* Filename: calc_price.c
* Description: Calculates the shipping cost for a given package.
* Author: Stav Menashe.
-------------------------------------------------------*/
#include <stdio.h>

#define CONST_SHIPPING_FEE (5.5)
#define SHIPPING_FEE_FOR_KG (11)
#define SHIPPING_FEE_FOR_CM (0.3)
#define SHIPPING_FEE_FOR_CM_DEV_KG (0.1)

double calculate_fee_per_kg(double p_weight);
double calculate_fee_per_cm(double p_len, double p_wid);
double calculate_fee_per_cm_dev_kg(double p_len, double p_wid, double p_weight);
double calculate_area(double len, double wid);

int main() {
    double p_len = 0, p_wid = 0, p_weight = 0;
    double fees_per_kg = 0, fees_per_cm = 0, fees_pre_cm_dev_kg = 0;
    double final_shipping_fee = 0;

    printf("What is the length (cm), width(cm) and weight(kg) of the package? (length width weight): ");
    scanf("%lf %lf %lf", &p_len, &p_wid, &p_weight);

    fees_per_kg = calculate_fee_per_kg(p_weight);
    fees_per_cm = calculate_fee_per_cm(p_len, p_wid);
    fees_pre_cm_dev_kg = calculate_fee_per_cm_dev_kg(p_len, p_wid, p_weight);
    
    final_shipping_fee = CONST_SHIPPING_FEE + fees_per_kg + fees_per_cm + fees_pre_cm_dev_kg;

    printf("The total fees of a package with area of %.2lf, and weight %.3lf, is %.2lf", p_weight, 
        calculate_area(p_len, p_wid), final_shipping_fee);


    return 0;
}

/*------------------------------------------------------
* Function Name - calculate_fee_per_kg 
* Function Purpose - Calculates the fees of a given weight of a package.
* Parameters – p_weight - The package weight.
* Return Values - The fees.
* Author - Stav Menahse.
-------------------------------------------------------*/
double calculate_fee_per_kg(double p_weight){
    return p_weight * SHIPPING_FEE_FOR_KG;
}

/*------------------------------------------------------
* Function Name - calculate_fee_per_cm 
* Function Purpose - Calculates the fees of a given sizes of a package.
* Parameters – p_len - The package length,
               p_wid - The width of the package.
* Return Values - The fees.
* Author - Stav Menahse.
-------------------------------------------------------*/
double calculate_fee_per_cm(double p_len, double p_wid){
    return calculate_area(p_len, p_wid) * SHIPPING_FEE_FOR_CM;
}

/*------------------------------------------------------
* Function Name - calculate_fee_per_cm_dev_kg 
* Function Purpose - Calculates the fees of a given sizes and weight of a package.
* Parameters – p_weight - The package weight,
               p_len - The package length,
               p_wid - The width of the package.
* Return Values - The fees.
* Author - Stav Menahse.
-------------------------------------------------------*/
double calculate_fee_per_cm_dev_kg(double p_len, double p_wid, double p_weight){
    if (p_weight == 0){
        return 0;
    }
    return (calculate_area(p_len, p_wid) / p_weight) * SHIPPING_FEE_FOR_CM_DEV_KG;
}

/*------------------------------------------------------
* Function Name - calculate_area 
* Function Purpose - Calculates the area of a given rectangle.
* Parameters – len - The length,
               wid - The width.
* Return Values - The area.
* Author - Stav Menahse.
-------------------------------------------------------*/
double calculate_area(double len, double wid){
    return len * wid;
}
