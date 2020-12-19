// loadfont.c

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <hw/inout.h>
#include <sys/neutrino.h>
#include <sys/mman.h>

unsigned int ScanLines = 0;   // 1..32
unsigned char Font[256][32];  // ���� � ⮬ �ଠ�, ����� �� ���� �
                              // ����������

uint8_t varMMR;
uint8_t varCPWER;
uint8_t varMIR;
uint8_t varMDR;
uint8_t varRPSR;

// �뢮� ���᪠���
void PrintHelp(void)
{
  printf("loadfont font_file\n");
  exit(EXIT_SUCCESS);
};

// ����⨥ ����㯠 �� ��஬� 梥⮢��� ᫮�
void OpenMap2(void)
{
  // cli
  InterruptDisable();

  // �믮��塞 �ᨭ�஭�� ��� ᨭ�஭�����
  out16(0x3C4, 0x0100);

  // ����頥� ����� �� ���� ���ᠬ � �㫥���� ᫮�,
  // � �� ������ ���ᠬ � ��ࢮ�� ᫮�
  out8(0x3C4, 0x04);
  varMMR = in8(0x3C5);         // 0x03
  out8(0x3C4, 0x04);           // 0x04
  out8(0x3C5, varMMR | 4);     // 0x07

  // ���뢠�� ����� �� ��஬� 梥⮢��� ᫮�
  out8(0x3C4, 0x02);
  varCPWER = in8(0x3C5);       // 0x03
  out16(0x3C4, 0x0402);        // 0x0402

  out16(0x3C4, 0x0300);

  // �⮡ࠦ��� ����������� �� ������� ���ᮢ A0000-BFFFF
  out8(0x3CE, 0x06);
  varMIR = in8(0x3CF);         // 0x0E
  out8(0x3CE, 0x06);
  out8(0x3CF, varMIR & 0xF1);  // 0x00
   
  // �⪫�砥� ࠧ������� ����㯠 �� ����/������ ���ᠬ
  // � ࠧ�� ᫮� ����������
  out8(0x3CE, 0x05);
  varMDR = in8(0x3CF);         // 0x10
  out8(0x3CE, 0x05);
  out8(0x3CF, varMDR & 0xEF);  // 0x00
  
  // ����砥� ����� �� �⥭�� ��ண� ᫮� ����������
  out8(0x3CE, 0x04);
  varRPSR = in8(0x3CF);        // 0x10
  out16(0x3CE, 0x0204);

  // sti
  InterruptEnable();  
};

// ����⠭������� ��ଠ�쭮� �������� ���������� ⥪�⮢��� ०���
void CloseMap2(void)
{
  // cli
  InterruptDisable();

  // �믮��塞 �ᨭ�஭�� ��� ᨭ�஭�����
  out16(0x3C4, 0x0100);

  // ����⠭�������� ���祭�� ॣ���� ��।������ 
  // �������� ����� (ॣ���� MMR)
  out8(0x3C4, 0x04);           // 0x04
  out8(0x3C5, varMMR);         // 0x03

  // ����⠭�������� ���祭�� ॣ���� ࠧ�襭��
  // ����� 梥⮢��� ᫮� (ॣ���� CPWER)
  out8(0x3C4, 0x02);           // 0x02
  out8(0x3C5, varCPWER);       // 0x03

  out16(0x3C4, 0x0300);

  // ����⠭�������� ���祭�� ॣ���� �����楫�����
  // �����祭�� (ॣ���� MIR)
  out8(0x3CE, 0x06);           // 0x06
  out8(0x3CF, varMIR);         // 0x0E
   
  // ����⠭�������� ���祭�� ॣ���� ०���
  // ࠡ��� (ॣ���� MDR)
  out8(0x3CE, 0x05);           // 0x05
  out8(0x3CF, varMDR);         // 0x10
  
  // ����⠭�������� ���祭�� ॣ���� �롮�
  // �⠥���� ᫮� (ॣ���� RPSR)
  out8(0x3CE, 0x04);           // 0x04
  out8(0x3CF, varRPSR);        // 0x00

  // sti
  InterruptEnable();  
};

// ����㧪� ���� � ����������
void SetFont(void)
{
  void           *addr              = NULL;
  void           *bios_addr         = NULL;
  unsigned short CrtIndexPort       = 0;
  unsigned int   VerticalDisplayEnd = 0;
  unsigned int   ScreenLines        = 0;  // 400, 350, 200
  unsigned char  Lines              = 0;  // 25, 50, 43, 28, ...
  uint8_t        varOVR;
  uint8_t        varULR;
  uint8_t        varCSR;
  uint8_t        varCER;
  uint8_t        varMSLR;
  uint8_t        varCGSR;

  // Request I/O privity
  if (ThreadCtl(_NTO_TCTL_IO, 0) == -1)
  {
    perror("ThreadCtl failed");
    exit(EXIT_FAILURE);
  };

  // ����砥� ����� �� ��஬� 梥⮢��� ᫮�
  OpenMap2();

  // To share memory with hardware such as video memory on an x86 platform:
  // Map in VGA display memory
  addr = mmap( 0, 65536, PROT_READ | PROT_WRITE, MAP_PHYS | MAP_SHARED, NOFD,
    0xA0000 );
  if (addr == MAP_FAILED)
  {
    perror("mmap failed");
    exit(EXIT_FAILURE);
  };

  // �����㥬 ���� � �����������
  memcpy(addr, &(Font[0][0]), 256 * 32);
    
  // ����⠭�������� ��ଠ���� �������� ���������� ⥪�⮢��� ०���
  CloseMap2();

  // Map in BIOS data
  bios_addr = mmap( 0, 256, PROT_READ | PROT_WRITE, MAP_PHYS | MAP_SHARED, NOFD,
    0x00400 );
  if (bios_addr == MAP_FAILED)
  {
    perror("mmap failed");
    exit(EXIT_FAILURE);
  };

  // ������⢮ ����� ࠧ���⪨ ��� ⥪�⮢�� ०����
  switch (*((char *) (bios_addr + 0x0089)) & 0x90)
  {
    case 0:
      ScreenLines = 350;
      break;
    case 0x10:
      ScreenLines = 400;
      break;
    case 0x80:
      ScreenLines = 200;
      break;
    default:
      ScreenLines = 400;
      break;
  };

  // ���� �����᭮�� ॣ���� ����஫��� ���
  CrtIndexPort = *((short *) (bios_addr + 0x0063));
  
  // ������⢮ ⥪�⮢�� ��ப �� �࠭�
  Lines = ScreenLines / ScanLines;

  // ������⢮ ⥪�⮢�� ��ப �� �࠭� ����� ������
  *((char  *) (bios_addr + 0x0084)) = (unsigned  char) (Lines - 1);

  // ���� ᨬ����� � ���ᥫ��
  *((short *) (bios_addr + 0x0085)) = (unsigned short) ScanLines;
  
  VerticalDisplayEnd = Lines * ScanLines - 1;  // 399, 391, ...

  // ���� ᨬ����� ⥪��, MSLR
  out8(CrtIndexPort, 0x09);
  varMSLR = in8(CrtIndexPort + 1);
  out8(CrtIndexPort, 0x09);
  out8(CrtIndexPort + 1, (varMSLR & 0xE0) | (ScanLines - 1));

  // ��������� �����ન����� ᨬ�����, ULR
  out8(CrtIndexPort, 0x14);
  varULR = in8(CrtIndexPort + 1);
  out8(CrtIndexPort, 0x14);
  out8(CrtIndexPort + 1, (varULR & 0xE0) | (ScanLines - 1));

  // �����襭�� �⮡ࠦ���� ���⨪��쭮� ࠧ���⪨, VDER
  out8(CrtIndexPort, 0x12);
  out8(CrtIndexPort + 1, VerticalDisplayEnd % 0x100);

  // �������⥫�� ॣ����, ���� D8 � D9 ॣ���� VDER
  out8(CrtIndexPort, 0x07);
  varOVR = in8(CrtIndexPort + 1);
  out8(CrtIndexPort, 0x07);
  out8(CrtIndexPort + 1, (varOVR & 0xBD) |
              (((VerticalDisplayEnd >> 8) & 0x01) << 1) |
              (((VerticalDisplayEnd >> 8) & 0x02) << 5)
      );

  // ��砫쭠� ����� �����, CSR
  out8(CrtIndexPort, 0x0A);
  varCSR = in8(CrtIndexPort + 1);
  out8(CrtIndexPort, 0x0A);
  out8(CrtIndexPort + 1, (varCSR & 0xE0) | (ScanLines - 2));

  *((char *) (bios_addr + 0x0061)) = (unsigned char) (ScanLines - 2);

  // ����筠� ����� �����, CER
  out8(CrtIndexPort, 0x0B);
  varCER = in8(CrtIndexPort + 1);
  out8(CrtIndexPort, 0x0B);
  out8(CrtIndexPort + 1, (varCER & 0xE0) | (ScanLines - 1));

  *((char *) (bios_addr + 0x0060)) = (unsigned char) (ScanLines - 1);
};

// �⥭�� ���� �� 䠩��
void ReadFont(char *filename)
{
  unsigned int i, j;
  unsigned int FileSize = 0;
  FILE         *infile  = NULL;  // input file

  printf("Loading font from %s\n", filename);

  // ����⨥ 䠩��
  if ((infile = fopen(filename, "rb")) == NULL)
  {
    perror("Can't open input file");
    exit(EXIT_FAILURE);
  };

  // ��।������ ����� 䠩��
  fseek(infile, 0, SEEK_END);
  FileSize = ftell(infile); 
  fseek(infile, 0, SEEK_SET);

  // ���᫥��� ����� ᨬ����
  ScanLines = FileSize / 256;

  // ������ 䠩�� ������ ���� ��⥭ 256
  if (FileSize != ScanLines * 256)
  {
    printf("Error: incorrect size of font file.\n");
    exit(EXIT_FAILURE);
  };

  // �⥭�� 䠩��
  for (i = 0; i < 256; i++)
  {
    for (j = 0; j < 32; j++)
    {
      if (j < ScanLines)
      {
        fread(&(Font[i][j]), 1, 1, infile);
      }
      else
      {
        Font[i][j] = 0;
      };
    };
  };

  // �����⨥ 䠩��
  fclose(infile);
};

int main(int argc, char *argv[], char *envp[]) 
{
  printf("loadfont - load font data into EGA or VGA cards\n\n");
  if (argc != 2)
  {
    PrintHelp();
    exit(EXIT_SUCCESS);
  };

  // �⥭�� ���� �� 䠩��
  ReadFont(argv[1]);

  // ����㧪� ���� � ����������
  SetFont();
};

