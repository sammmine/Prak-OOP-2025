#ifndef GOALKEEPER_HPP
#define GOALKEEPER_HPP

#include "Footballer.hpp"

class Goalkeeper : public Footballer
{
protected:
  // atribut tambahan cleanSheets (jumlah pertandingan tanpa kebobolan),
  // saves (jumlah penyelamatan), dan totalShotsOnGoal (jumlah total tendangan ke gawang)
  // ...
  int cleanSheets;
  int saves;
  int totalShotsOnGoal;

public:
  // Default constructor
  // set atribut Footballer dengan nilai default,
  // set cleanSheets, saves, totalShotsOnGoal ke 0, playPosition ke "goalkeeper"
  // ...
  Goalkeeper() ;

  // User-defined constructor
  // parameter: string name, int birthYear, int cleanSheets, int saves, int totalShotsOnGoal
  // set atribut dengan nilai parameter, playPosition tetap "goalkeeper"
  // nationality, height, dan weight gunakan nilai default superclass
  // ...
  Goalkeeper(string n, int b, int c, int s, int t) ;

  // Getter dan Setter untuk cleanSheets
  // setCleanSheets(...)
  // getCleanSheets()
  int setCleanSheets(int s) ;
  int getCleanSheets() const ;

  // Getter dan Setter untuk saves
  // setSaves(...)
  // getSaves()
  int setSaves(int s) ;
  int getSaves() const ;

  // Getter dan Setter untuk totalShotsOnGoal
  // setTotalShotsOnGoal(...)
  // getTotalShotsOnGoal()
  int setTotalShotsOnGoal(int s) ;
  int getTotalShotsOnGoal() const ;

  // Method tambahan: savePercentage
  // rumus: (saves / totalShotsOnGoal) * 100
  // return dalam bentuk float
  // ...
  float savePercentage() ;

  // Override transferRate:
  // rumus: (700.000 * cleanSheets) + (50.000 * saves)
  // hasil berupa int
  // ...
  int transferRate() ;

  // Override displayInfo():
  // Cetak info Footballer + atribut tambahan goalkeeper (cleanSheets, saves, savePercentage)
  // Format:
  // Clean Sheets: <cleanSheets>
  // Saves: <saves>
  // Save Percentage: <savePercentage>%
  void displayInfo() ;
  
  // Hint: Gunakan fixed dan setprecision(2) untuk menampilkan conversionRate
  // Contoh: cout << fixed << setprecision(2) << conversionRate() << "%" << endl;
  // ...
};

#endif
