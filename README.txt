============================================================================
Description : 
This program is a Group Calculator. 
Overall, there are 5 operations available : Union, Intersection, Difference, Product, Composite
Program will start and print the list of 3 basic operations on 2 groups which are :  Union, Intersection, Difference.
User can add operation to list of use the calculator groups :
- Use the calculator by writing the command "eval ..." (number of wanted operation) , 
enter a serie of numbers as group when the first number is the size of current receiving group and so on.
Print the input splitted to groups, operations of each between them and final result. 
(Each operation will print from itself class)
- Add operations to the list by writing the wanted operations and two listed operations from the list - it will be considered as complicated opertaion.
Classes Union, Intersection, Difference inheritance from Class Operation.
CompOperation also inheritance from Operation,
and CompUnion, CompIntersection, CompDifference inheritance from CompOperation.
  
==============================================================================  

Files list :
Header Files :
Consts.h			-> קובץ header לשמירת משתנים קבועים
GroupCalculator.h 		-> מחלקה לניהול סדר הפעולות במחשבון
Set.h			-> מחלקה לניהול הקבוצות עצמן, קבלת והכנסה לוקטור
Operation.h		-> מחלקה לניהול הפעולות על הקבוצות (מורישה למחלקות הפעולות האחרות)
Union.h			-> מחלקה לניהול פעולת האיחוד
Intersection.h		-> מחלקה לניהול פעולת החיתוך
Difference.h		-> מחלקה לניהול פעולת החיסור
CompOperation.h		-> מחלקה לניהול הפעולות המורכבות על הקבוצות (יורשת מ-Operation)
CompUnion.h		-> מחלקה לניהול פעולת האיחוד (מורכבת)
CompIntersection.h	-> מחלקה לניהול פעולת החיתוך (מורכבת)
CompDifference.h		-> מחלקה לניהול פעולת החיסור (מורכבת)
CompProduct.h		-> מחלקה לניהול פעולת הכפל (מורכבת)
Composite.h		-> מחלקה לניהול פעולת ההרכבה (מורכבת)

.cpp Files :
main.cpp             		->
GroupCalculator.cpp 	-> מחלקה לניהול סדר הפעולות במחשבון (לולאה ראשית לתוכנית, קריאה להדפסת רשימת הפעולות, מחזיקה וקטור קבוצות, תוצאות)
Set.cpp			->מחלקה לניהול הקבוצות עצמן, קבלת והכנסה לוקטור
Operation.cpp		-> מחלקה זו אחראית על החזקת המשתנים הנדרשים לפעולות (כמות קבוצות לקבל, סימן, וכו'...)
Union.cpp		-> מחלקה זו מפעילה את פעולת האיחוד על 2 הקבוצות שקיבלה
Intersection.cpp		-> מחלקה זו מפעילה את פעולת החיתוך על 2 הקבוצות שקיבלה
Difference.cpp		-> מחלקה זו מפעילה את פעולת החיסור על 2 הקבוצות שקיבלה
CompOperation.cpp	-> מחלקה זו אחראית על הפעלת הפעולות המורכבות
CompUnion.cpp		-> מחלקה זו מפעילה את פעולת האיחוד (המורכבת) הקבוצות שקיבלה
CompIntersection.cpp	-> מחלקה זו מפעילה את פעולת החיתוך (המורכבת) הקבוצות שקיבלה
CompDifference.cpp	-> מחלקה זו מפעילה את פעולת החיסור (המורכבת) הקבוצות שקיבלה
CompProduct.cpp		-> מחלקה זו מפעילה את פעולת הכפל (המורכבת) בין הקבוצות שקיבלה
Composite.cpp		-> מחלקה זו מפעילה את פעולת ההרכבה (מורכבת) הקבוצות שקיבלה


==============================================================================

Data Structure :
vector of shared_ptr to hold each pointer in a single group, vector of shared_ptr to hold the operations list,

============================================================================
Full-Names : Yehonatan Bakshi & Hila Saadon
