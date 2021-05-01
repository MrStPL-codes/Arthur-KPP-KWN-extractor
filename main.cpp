#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    string nameOfFile;
    cout << "Enter name of file: ";
    cin >> nameOfFile;

    fstream file;
    file.open( nameOfFile.c_str(), ios::binary | ios::in );

    if(!file.good())
    {
        cout << nameOfFile << "\t\tNot found!" << endl;
        cout << endl; cout << "Press any key to exit...";
        cin.get();cin.get();
        return 0;
    } cout << nameOfFile << "\t\tOK" << endl;



    string nameOfNewFile = nameOfFile + ".txt";
    fstream newFile;
    newFile.open( nameOfNewFile.c_str(), ios::binary | ios::out );
    cout << nameOfNewFile << "\t\tCreate" << endl;


    fstream dump;
    dump.open("ArthurDump.bin", ios::binary | ios::out);
    cout << "ArthurDump.bin\t\tCreate" << endl;


    char little_endian[2] = { 0xFF, 0xFE };
    char breakLine[4] = { 0x0D, 0x00, 0x0A, 0x00 };
    char buffor[2] = { 0x00, 0x00 };
    char spaceForNewString[2] = { 0xFF, 0xFF };
    char null[2] = { 0x00, 0x00 };
    bool active = false;
    newFile.write(little_endian, 2);

    char ascii[192] = { 0x20, 0x00, 0x21, 0x00, 0x22, 0x00, 0x23, 0x00, 0x24, 0x00,
                        0x25, 0x00, 0x26, 0x00, 0x27, 0x00, 0x28, 0x00, 0x29, 0x00,
                        0x2A, 0x00, 0x2B, 0x00, 0x2C, 0x00, 0x2D, 0x00, 0x2E, 0x00,
                        0x2F, 0x00, 0x30, 0x00, 0x31, 0x00, 0x32, 0x00, 0x33, 0x00,
                        0x34, 0x00, 0x35, 0x00, 0x36, 0x00, 0x37, 0x00, 0x38, 0x00,
                        0x39, 0x00, 0x3A, 0x00, 0x3B, 0x00, 0x3C, 0x00, 0x3D, 0x00,
                        0x3E, 0x00, 0x3F, 0x00, 0x40, 0x00, 0x41, 0x00, 0x42, 0x00,
                        0x43, 0x00, 0x44, 0x00, 0x45, 0x00, 0x46, 0x00, 0x47, 0x00,
                        0x48, 0x00, 0x49, 0x00, 0x4A, 0x00, 0x4B, 0x00, 0x4C, 0x00,
                        0x4D, 0x00, 0x4E, 0x00, 0x4F, 0x00, 0x50, 0x00, 0x51, 0x00,
                        0x52, 0x00, 0x53, 0x00, 0x54, 0x00, 0x55, 0x00, 0x56, 0x00,
                        0x57, 0x00, 0x58, 0x00, 0x59, 0x00, 0x5A, 0x00, 0x5B, 0x00,
                        0x5C, 0x00, 0x5D, 0x00, 0x5E, 0x00, 0x5F, 0x00, 0x60, 0x00,
                        0x61, 0x00, 0x62, 0x00, 0x63, 0x00, 0x64, 0x00, 0x65, 0x00,
                        0x66, 0x00, 0x67, 0x00, 0x68, 0x00, 0x69, 0x00, 0x6A, 0x00,
                        0x6B, 0x00, 0x6C, 0x00, 0x6D, 0x00, 0x6E, 0x00, 0x6F, 0x00,
                        0x70, 0x00, 0x71, 0x00, 0x72, 0x00, 0x73, 0x00, 0x74, 0x00,
                        0x75, 0x00, 0x76, 0x00, 0x77, 0x00, 0x78, 0x00, 0x79, 0x00,
                        0x7A, 0x00, 0x7B, 0x00, 0x7C, 0x00, 0x7D, 0x00, 0x7E, 0x00,
                        0xA3, 0x00 };

    char polishChar[36] = { 0x04, 0x01, 0x05, 0x01, 0x06, 0x01, 0x07, 0x01,     //¥ ¹ Æ æ
                            0x18, 0x01, 0x19, 0x01, 0x41, 0x01, 0x42, 0x01,     //Ê ê £ ³
                            0x43, 0x01, 0x44, 0x01, 0xD3, 0x00, 0xF3, 0x00,     //Ñ ñ Ó ó
                            0x5A, 0x01, 0x5B, 0x01, 0x79, 0x01, 0x7A, 0x01,     //Œ œ  Ÿ
                            0x7B, 0x01, 0x7C, 0x01 };                           //¯ ¿

    while(!file.eof())
    {
        file.read(buffor, 2);
        if(
                (buffor[0]==ascii[0]) || (buffor[0]==ascii[2]) || (buffor[0]==ascii[4]) ||
                (buffor[0]==ascii[6]) || (buffor[0]==ascii[8]) || (buffor[0]==ascii[10]) ||
                (buffor[0]==ascii[12]) || (buffor[0]==ascii[14]) || (buffor[0]==ascii[16]) ||
                (buffor[0]==ascii[18]) || (buffor[0]==ascii[20]) || (buffor[0]==ascii[22]) ||
                (buffor[0]==ascii[24]) || (buffor[0]==ascii[26]) || (buffor[0]==ascii[28]) ||
                (buffor[0]==ascii[30]) || (buffor[0]==ascii[32]) || (buffor[0]==ascii[34]) ||
                (buffor[0]==ascii[36]) || (buffor[0]==ascii[38]) || (buffor[0]==ascii[40]) ||
                (buffor[0]==ascii[42]) || (buffor[0]==ascii[44]) || (buffor[0]==ascii[46]) ||
                (buffor[0]==ascii[48]) || (buffor[0]==ascii[50]) || (buffor[0]==ascii[52]) ||
                (buffor[0]==ascii[54]) || (buffor[0]==ascii[56]) || (buffor[0]==ascii[58]) ||
                (buffor[0]==ascii[60]) || (buffor[0]==ascii[62]) || (buffor[0]==ascii[64]) ||
                (buffor[0]==ascii[66]) || (buffor[0]==ascii[68]) || (buffor[0]==ascii[70]) ||
                (buffor[0]==ascii[72]) || (buffor[0]==ascii[74]) || (buffor[0]==ascii[76]) ||
                (buffor[0]==ascii[78]) || (buffor[0]==ascii[80]) || (buffor[0]==ascii[82]) ||
                (buffor[0]==ascii[84]) || (buffor[0]==ascii[86]) || (buffor[0]==ascii[88]) ||
                (buffor[0]==ascii[90]) || (buffor[0]==ascii[92]) || (buffor[0]==ascii[94]) ||
                (buffor[0]==ascii[96]) || (buffor[0]==ascii[98]) || (buffor[0]==ascii[100]) ||
                (buffor[0]==ascii[102]) || (buffor[0]==ascii[104]) || (buffor[0]==ascii[106]) ||
                (buffor[0]==ascii[108]) || (buffor[0]==ascii[110]) || (buffor[0]==ascii[112]) ||
                (buffor[0]==ascii[114]) || (buffor[0]==ascii[116]) || (buffor[0]==ascii[118]) ||
                (buffor[0]==ascii[120]) || (buffor[0]==ascii[122]) || (buffor[0]==ascii[124]) ||
                (buffor[0]==ascii[126]) || (buffor[0]==ascii[128]) || (buffor[0]==ascii[130]) ||
                (buffor[0]==ascii[132]) || (buffor[0]==ascii[134]) || (buffor[0]==ascii[136]) ||
                (buffor[0]==ascii[138]) || (buffor[0]==ascii[140]) || (buffor[0]==ascii[142]) ||
                (buffor[0]==ascii[144]) || (buffor[0]==ascii[146]) || (buffor[0]==ascii[148]) ||
                (buffor[0]==ascii[150]) || (buffor[0]==ascii[152]) || (buffor[0]==ascii[154]) ||
                (buffor[0]==ascii[156]) || (buffor[0]==ascii[158]) || (buffor[0]==ascii[160]) ||
                (buffor[0]==ascii[162]) || (buffor[0]==ascii[164]) || (buffor[0]==ascii[166]) ||
                (buffor[0]==ascii[168]) || (buffor[0]==ascii[170]) || (buffor[0]==ascii[172]) ||
                (buffor[0]==ascii[174]) || (buffor[0]==ascii[176]) || (buffor[0]==ascii[178]) ||
                (buffor[0]==ascii[180]) || (buffor[0]==ascii[182]) || (buffor[0]==ascii[184]) ||
                (buffor[0]==ascii[186]) || (buffor[0]==ascii[188]) || (buffor[0]==ascii[190]) ||
                ((buffor[0]==polishChar[0]) && (buffor[1]==polishChar[1])) ||
                ((buffor[0]==polishChar[2]) && (buffor[1]==polishChar[3])) ||
                ((buffor[0]==polishChar[4]) && (buffor[1]==polishChar[5])) ||
                ((buffor[0]==polishChar[6]) && (buffor[1]==polishChar[7])) ||
                ((buffor[0]==polishChar[8]) && (buffor[1]==polishChar[9])) ||
                ((buffor[0]==polishChar[10]) && (buffor[1]==polishChar[11])) ||
                ((buffor[0]==polishChar[12]) && (buffor[1]==polishChar[13])) ||
                ((buffor[0]==polishChar[14]) && (buffor[1]==polishChar[15])) ||
                ((buffor[0]==polishChar[16]) && (buffor[1]==polishChar[17])) ||
                ((buffor[0]==polishChar[18]) && (buffor[1]==polishChar[19])) ||
                ((buffor[0]==polishChar[20]) && (buffor[1]==polishChar[21])) ||
                ((buffor[0]==polishChar[22]) && (buffor[1]==polishChar[23])) ||
                ((buffor[0]==polishChar[24]) && (buffor[1]==polishChar[25])) ||
                ((buffor[0]==polishChar[26]) && (buffor[1]==polishChar[27])) ||
                ((buffor[0]==polishChar[28]) && (buffor[1]==polishChar[29])) ||
                ((buffor[0]==polishChar[30]) && (buffor[1]==polishChar[31])) ||
                ((buffor[0]==polishChar[32]) && (buffor[1]==polishChar[33])) ||
                ((buffor[0]==polishChar[34]) && (buffor[1]==polishChar[35]))
           )
           {
               file.read(buffor, 2);

               if(
                    (buffor[0]==ascii[0]) || (buffor[0]==ascii[2]) || (buffor[0]==ascii[4]) ||
                    (buffor[0]==ascii[6]) || (buffor[0]==ascii[8]) || (buffor[0]==ascii[10]) ||
                    (buffor[0]==ascii[12]) || (buffor[0]==ascii[14]) || (buffor[0]==ascii[16]) ||
                    (buffor[0]==ascii[18]) || (buffor[0]==ascii[20]) || (buffor[0]==ascii[22]) ||
                    (buffor[0]==ascii[24]) || (buffor[0]==ascii[26]) || (buffor[0]==ascii[28]) ||
                    (buffor[0]==ascii[30]) || (buffor[0]==ascii[32]) || (buffor[0]==ascii[34]) ||
                    (buffor[0]==ascii[36]) || (buffor[0]==ascii[38]) || (buffor[0]==ascii[40]) ||
                    (buffor[0]==ascii[42]) || (buffor[0]==ascii[44]) || (buffor[0]==ascii[46]) ||
                    (buffor[0]==ascii[48]) || (buffor[0]==ascii[50]) || (buffor[0]==ascii[52]) ||
                    (buffor[0]==ascii[54]) || (buffor[0]==ascii[56]) || (buffor[0]==ascii[58]) ||
                    (buffor[0]==ascii[60]) || (buffor[0]==ascii[62]) || (buffor[0]==ascii[64]) ||
                    (buffor[0]==ascii[66]) || (buffor[0]==ascii[68]) || (buffor[0]==ascii[70]) ||
                    (buffor[0]==ascii[72]) || (buffor[0]==ascii[74]) || (buffor[0]==ascii[76]) ||
                    (buffor[0]==ascii[78]) || (buffor[0]==ascii[80]) || (buffor[0]==ascii[82]) ||
                    (buffor[0]==ascii[84]) || (buffor[0]==ascii[86]) || (buffor[0]==ascii[88]) ||
                    (buffor[0]==ascii[90]) || (buffor[0]==ascii[92]) || (buffor[0]==ascii[94]) ||
                    (buffor[0]==ascii[96]) || (buffor[0]==ascii[98]) || (buffor[0]==ascii[100]) ||
                    (buffor[0]==ascii[102]) || (buffor[0]==ascii[104]) || (buffor[0]==ascii[106]) ||
                    (buffor[0]==ascii[108]) || (buffor[0]==ascii[110]) || (buffor[0]==ascii[112]) ||
                    (buffor[0]==ascii[114]) || (buffor[0]==ascii[116]) || (buffor[0]==ascii[118]) ||
                    (buffor[0]==ascii[120]) || (buffor[0]==ascii[122]) || (buffor[0]==ascii[124]) ||
                    (buffor[0]==ascii[126]) || (buffor[0]==ascii[128]) || (buffor[0]==ascii[130]) ||
                    (buffor[0]==ascii[132]) || (buffor[0]==ascii[134]) || (buffor[0]==ascii[136]) ||
                    (buffor[0]==ascii[138]) || (buffor[0]==ascii[140]) || (buffor[0]==ascii[142]) ||
                    (buffor[0]==ascii[144]) || (buffor[0]==ascii[146]) || (buffor[0]==ascii[148]) ||
                    (buffor[0]==ascii[150]) || (buffor[0]==ascii[152]) || (buffor[0]==ascii[154]) ||
                    (buffor[0]==ascii[156]) || (buffor[0]==ascii[158]) || (buffor[0]==ascii[160]) ||
                    (buffor[0]==ascii[162]) || (buffor[0]==ascii[164]) || (buffor[0]==ascii[166]) ||
                    (buffor[0]==ascii[168]) || (buffor[0]==ascii[170]) || (buffor[0]==ascii[172]) ||
                    (buffor[0]==ascii[174]) || (buffor[0]==ascii[176]) || (buffor[0]==ascii[178]) ||
                    (buffor[0]==ascii[180]) || (buffor[0]==ascii[182]) || (buffor[0]==ascii[184]) ||
                    (buffor[0]==ascii[186]) || (buffor[0]==ascii[188]) || (buffor[0]==ascii[190]) ||
                    ((buffor[0]==polishChar[0]) && (buffor[1]==polishChar[1])) ||
                    ((buffor[0]==polishChar[2]) && (buffor[1]==polishChar[3])) ||
                    ((buffor[0]==polishChar[4]) && (buffor[1]==polishChar[5])) ||
                    ((buffor[0]==polishChar[6]) && (buffor[1]==polishChar[7])) ||
                    ((buffor[0]==polishChar[8]) && (buffor[1]==polishChar[9])) ||
                    ((buffor[0]==polishChar[10]) && (buffor[1]==polishChar[11])) ||
                    ((buffor[0]==polishChar[12]) && (buffor[1]==polishChar[13])) ||
                    ((buffor[0]==polishChar[14]) && (buffor[1]==polishChar[15])) ||
                    ((buffor[0]==polishChar[16]) && (buffor[1]==polishChar[17])) ||
                    ((buffor[0]==polishChar[18]) && (buffor[1]==polishChar[19])) ||
                    ((buffor[0]==polishChar[20]) && (buffor[1]==polishChar[21])) ||
                    ((buffor[0]==polishChar[22]) && (buffor[1]==polishChar[23])) ||
                    ((buffor[0]==polishChar[24]) && (buffor[1]==polishChar[25])) ||
                    ((buffor[0]==polishChar[26]) && (buffor[1]==polishChar[27])) ||
                    ((buffor[0]==polishChar[28]) && (buffor[1]==polishChar[29])) ||
                    ((buffor[0]==polishChar[30]) && (buffor[1]==polishChar[31])) ||
                    ((buffor[0]==polishChar[32]) && (buffor[1]==polishChar[33])) ||
                    ((buffor[0]==polishChar[34]) && (buffor[1]==polishChar[35]))
                  )
               {
                   file.seekg(-4, ios::cur);
                   while(buffor[0]!=null[0])
                   {
                       file.read(buffor, 2);
                       if(buffor[0]!=null[0])
                            newFile.write(buffor, 2);
                   }
                   newFile.write(breakLine, 4);
                   dump.write(spaceForNewString, 2);
                   dump.write(buffor, 2);
               }
               else
               {
                   file.seekg(-4, ios::cur);
                   file.read(buffor, 2);
                   if(!file.eof())dump.write(buffor, 2);
                   file.read(buffor, 2);
                   if(!file.eof())dump.write(buffor, 2);
               }
           }
           else if(!file.eof())dump.write(buffor, 2);

    }




    cout << nameOfNewFile << "\t\tDone" << endl;
    dump.close(); cout << "ArthurDump.bin\t\tDone" << endl;
    file.close(); cout << nameOfFile << "\t\tClose" << endl;
    newFile.close(); cout << nameOfNewFile << "\t\tClose" << endl;
    cout << "DONE!\t\t\tAuthor: MrStPL" << endl;
    cout << endl; cout << "Press ENTER to exit...";
    cin.get();cin.get();
    return 0;
}
