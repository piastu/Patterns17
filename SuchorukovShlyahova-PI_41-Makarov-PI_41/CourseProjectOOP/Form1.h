#pragma once
#include <string.h>
#include <stdlib.h>
#include "Wagon.h"
#include "Wagon.cpp"
#include "Pas.h"
#include "Pas.cpp"
#include "Slu.h"
#include <vector>
#include <algorithm>
#include <clocale>



namespace kurs11 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
    using namespace System::Collections::Generic;
    using namespace System::IO;
	using namespace std;

		/// <summary>
	/// Summary for Form1
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
#pragma region

private: System::Windows::Forms::Label^  label4;
private: System::Windows::Forms::Label^  label3;
private: System::Windows::Forms::ToolStripMenuItem^  Ù‡ÈÎToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  ‚˚ıÓ‰ToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  ÔÓÏÓ˘¸ToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  ÛÍÓ‚Ó‰ÒÚ‚ÓœÓÎ¸ÁÓ‚‡ÚÂÎˇToolStripMenuItem;
private: System::Windows::Forms::MenuStrip^  menuStrip1;
private: System::Windows::Forms::Timer^  timer1;
private: System::Windows::Forms::TabPage^  tabPage3;
private: System::Windows::Forms::Panel^  panel3;
private: System::Windows::Forms::PictureBox^  pictureBox8;
private: System::Windows::Forms::Button^  button1;
private: System::Windows::Forms::Label^  label5;
private: System::Windows::Forms::Panel^  panel4;
private: System::Windows::Forms::Button^  button6;
private: System::Windows::Forms::Button^  button10;
private: System::Windows::Forms::PictureBox^  pictureBox5;
private: System::Windows::Forms::Button^  button11;
private: System::Windows::Forms::PictureBox^  pictureBox7;
private: System::Windows::Forms::PictureBox^  pictureBox10;
private: System::Windows::Forms::PictureBox^  pictureBox11;
private: System::Windows::Forms::PictureBox^  pictureBox12;
private: System::Windows::Forms::PictureBox^  pictureBox13;
private: System::Windows::Forms::PictureBox^  pictureBox14;
private: System::Windows::Forms::PictureBox^  pictureBox15;
private: System::Windows::Forms::PictureBox^  pictureBox16;
private: System::Windows::Forms::PictureBox^  pictureBox17;
private: System::Windows::Forms::PictureBox^  pictureBox18;
private: System::Windows::Forms::PictureBox^  pictureBox19;
private: System::Windows::Forms::PictureBox^  pictureBox20;
private: System::Windows::Forms::PictureBox^  pictureBox21;
private: System::Windows::Forms::PictureBox^  pictureBox22;
private: System::Windows::Forms::PictureBox^  pictureBox23;
private: System::Windows::Forms::PictureBox^  pictureBox24;
private: System::Windows::Forms::PictureBox^  pictureBox25;
private: System::Windows::Forms::PictureBox^  pictureBox26;
private: System::Windows::Forms::PictureBox^  pictureBox27;
private: System::Windows::Forms::PictureBox^  pictureBox28;
private: System::Windows::Forms::PictureBox^  pictureBox29;
private: System::Windows::Forms::PictureBox^  pictureBox30;
private: System::Windows::Forms::PictureBox^  pictureBox31;
private: System::Windows::Forms::Panel^  panel8;
private: System::Windows::Forms::PictureBox^  pictureBox32;
private: System::Windows::Forms::Button^  button12;
private: System::Windows::Forms::Label^  label6;
private: System::Windows::Forms::Panel^  panel9;
private: System::Windows::Forms::PictureBox^  pictureBox33;
private: System::Windows::Forms::Button^  button13;
private: System::Windows::Forms::Label^  label8;
private: System::Windows::Forms::Panel^  panel10;
private: System::Windows::Forms::PictureBox^  pictureBox34;
private: System::Windows::Forms::Button^  button14;
private: System::Windows::Forms::Label^  label10;
private: System::Windows::Forms::TabPage^  tabPage4;
private: System::Windows::Forms::Panel^  panel11;
private: System::Windows::Forms::PictureBox^  pictureBox35;
private: System::Windows::Forms::Button^  button15;
private: System::Windows::Forms::Label^  label11;
private: System::Windows::Forms::Panel^  panel12;
private: System::Windows::Forms::Button^  button16;
private: System::Windows::Forms::Button^  button17;
private: System::Windows::Forms::PictureBox^  pictureBox36;
private: System::Windows::Forms::Button^  button18;
private: System::Windows::Forms::PictureBox^  pictureBox37;
private: System::Windows::Forms::PictureBox^  pictureBox38;
private: System::Windows::Forms::PictureBox^  pictureBox39;
private: System::Windows::Forms::PictureBox^  pictureBox40;
private: System::Windows::Forms::PictureBox^  pictureBox41;
private: System::Windows::Forms::PictureBox^  pictureBox42;
private: System::Windows::Forms::PictureBox^  pictureBox43;
private: System::Windows::Forms::PictureBox^  pictureBox44;
private: System::Windows::Forms::PictureBox^  pictureBox45;
private: System::Windows::Forms::PictureBox^  pictureBox46;
private: System::Windows::Forms::PictureBox^  pictureBox47;
private: System::Windows::Forms::PictureBox^  pictureBox48;
private: System::Windows::Forms::PictureBox^  pictureBox49;
private: System::Windows::Forms::PictureBox^  pictureBox50;
private: System::Windows::Forms::PictureBox^  pictureBox51;
private: System::Windows::Forms::PictureBox^  pictureBox52;
private: System::Windows::Forms::PictureBox^  pictureBox53;
private: System::Windows::Forms::PictureBox^  pictureBox54;
private: System::Windows::Forms::PictureBox^  pictureBox55;
private: System::Windows::Forms::PictureBox^  pictureBox56;
private: System::Windows::Forms::PictureBox^  pictureBox57;
private: System::Windows::Forms::PictureBox^  pictureBox58;
private: System::Windows::Forms::PictureBox^  pictureBox59;
private: System::Windows::Forms::Panel^  panel13;
private: System::Windows::Forms::PictureBox^  pictureBox60;
private: System::Windows::Forms::Button^  button19;
private: System::Windows::Forms::Label^  label12;
private: System::Windows::Forms::Panel^  panel14;
private: System::Windows::Forms::PictureBox^  pictureBox61;
private: System::Windows::Forms::Button^  button20;
private: System::Windows::Forms::Label^  label13;
private: System::Windows::Forms::Panel^  panel15;
private: System::Windows::Forms::PictureBox^  pictureBox62;
private: System::Windows::Forms::Button^  button21;
private: System::Windows::Forms::Label^  label14;
private: System::Windows::Forms::Panel^  panel16;
private: System::Windows::Forms::PictureBox^  pictureBox63;
private: System::Windows::Forms::Button^  button22;
private: System::Windows::Forms::Label^  label15;
private: System::Windows::Forms::Panel^  panel17;
private: System::Windows::Forms::Button^  button23;
private: System::Windows::Forms::Button^  button24;
private: System::Windows::Forms::PictureBox^  pictureBox64;
private: System::Windows::Forms::Button^  button25;
private: System::Windows::Forms::PictureBox^  pictureBox65;
private: System::Windows::Forms::PictureBox^  pictureBox66;
private: System::Windows::Forms::PictureBox^  pictureBox67;
private: System::Windows::Forms::PictureBox^  pictureBox68;
private: System::Windows::Forms::PictureBox^  pictureBox69;
private: System::Windows::Forms::PictureBox^  pictureBox70;
private: System::Windows::Forms::PictureBox^  pictureBox71;
private: System::Windows::Forms::PictureBox^  pictureBox72;
private: System::Windows::Forms::PictureBox^  pictureBox73;
private: System::Windows::Forms::PictureBox^  pictureBox74;
private: System::Windows::Forms::PictureBox^  pictureBox75;
private: System::Windows::Forms::PictureBox^  pictureBox76;
private: System::Windows::Forms::PictureBox^  pictureBox77;
private: System::Windows::Forms::PictureBox^  pictureBox78;
private: System::Windows::Forms::PictureBox^  pictureBox79;
private: System::Windows::Forms::PictureBox^  pictureBox80;
private: System::Windows::Forms::PictureBox^  pictureBox81;
private: System::Windows::Forms::PictureBox^  pictureBox82;
private: System::Windows::Forms::PictureBox^  pictureBox83;
private: System::Windows::Forms::PictureBox^  pictureBox84;
private: System::Windows::Forms::PictureBox^  pictureBox85;
private: System::Windows::Forms::PictureBox^  pictureBox86;
private: System::Windows::Forms::PictureBox^  pictureBox87;
private: System::Windows::Forms::Panel^  panel18;
private: System::Windows::Forms::PictureBox^  pictureBox88;
private: System::Windows::Forms::Button^  button26;
private: System::Windows::Forms::Label^  label16;
private: System::Windows::Forms::Panel^  panel19;
private: System::Windows::Forms::PictureBox^  pictureBox89;
private: System::Windows::Forms::Button^  button27;
private: System::Windows::Forms::Label^  label17;
private: System::Windows::Forms::Panel^  panel20;
private: System::Windows::Forms::PictureBox^  pictureBox90;
private: System::Windows::Forms::Button^  button28;
private: System::Windows::Forms::Label^  label18;
private: System::Windows::Forms::TabPage^  Imitation;
private: System::Windows::Forms::Panel^  panel22;
private: System::Windows::Forms::PictureBox^  pictureBox92;
private: System::Windows::Forms::Button^  button30;
private: System::Windows::Forms::Label^  label20;
private: System::Windows::Forms::Panel^  panel23;
private: System::Windows::Forms::Button^  button31;
private: System::Windows::Forms::Button^  button32;












private: System::Windows::Forms::PictureBox^  sec0;



private: System::Windows::Forms::PictureBox^  hour4;
private: System::Windows::Forms::PictureBox^  ten_hour;


private: System::Windows::Forms::PictureBox^  hour2;

private: System::Windows::Forms::Panel^  panel24;
private: System::Windows::Forms::PictureBox^  pictureBox117;
private: System::Windows::Forms::Button^  buttonbar;
private: System::Windows::Forms::Label^  label21;
private: System::Windows::Forms::Panel^  panel25;
private: System::Windows::Forms::PictureBox^  pictureBox118;
private: System::Windows::Forms::Button^  buttonzim;
private: System::Windows::Forms::Label^  label22;
private: System::Windows::Forms::Panel^  panel21;
private: System::Windows::Forms::PictureBox^  pictureBox91;
private: System::Windows::Forms::Button^  buttoncom;
private: System::Windows::Forms::Label^  label19;
private: System::Windows::Forms::TabControl^  tabImitation;
private: System::Windows::Forms::TabPage^  tabPage1;
private: System::Windows::Forms::TabPage^  tabPage5;
private: System::Windows::Forms::TabPage^  tabPage6;
private: System::Windows::Forms::TabPage^  tabPage7;
private: System::Windows::Forms::TabPage^  tabPage8;
private: System::Windows::Forms::Panel^  panel2;
private: System::Windows::Forms::Label^  label7;
private: System::Windows::Forms::Label^  label1;
private: System::Windows::Forms::TextBox^  surname;
private: System::Windows::Forms::Label^  label2;
private: System::Windows::Forms::Label^  label25;
private: System::Windows::Forms::Label^  label26;
private: System::Windows::Forms::ComboBox^  comboBox2;
private: System::Windows::Forms::CheckBox^  checkBox4;
private: System::Windows::Forms::CheckBox^  checkBox3;
private: System::Windows::Forms::CheckBox^  checkBox2;
private: System::Windows::Forms::CheckBox^  checkBox1;
private: System::Windows::Forms::Label^  label9;
private: System::Windows::Forms::Button^  buttonval;
private: System::Windows::Forms::Label^  zimnaz2;
private: System::Windows::Forms::Label^  label31;
private: System::Windows::Forms::Label^  label29;
private: System::Windows::Forms::Label^  label28;
private: System::Windows::Forms::Label^  label27;
private: System::Windows::Forms::Label^  com1;
private: System::Windows::Forms::Label^  label32;
private: System::Windows::Forms::Label^  comnaz3;
private: System::Windows::Forms::Label^  comnaz1;
private: System::Windows::Forms::Label^  label33;
private: System::Windows::Forms::Label^  comnum1;
private: System::Windows::Forms::Label^  bar2;
private: System::Windows::Forms::Label^  label37;
private: System::Windows::Forms::Label^  label39;
private: System::Windows::Forms::Label^  comnum2;
private: System::Windows::Forms::Label^  label54;
private: System::Windows::Forms::Label^  zim2;
private: System::Windows::Forms::Label^  label53;
private: System::Windows::Forms::Label^  label52;
private: System::Windows::Forms::Label^  com2;
private: System::Windows::Forms::Label^  zim1;
private: System::Windows::Forms::Label^  label58;
private: System::Windows::Forms::Label^  comnaz2;
private: System::Windows::Forms::Label^  comnum3;
private: System::Windows::Forms::Label^  label59;
private: System::Windows::Forms::Label^  com3;
private: System::Windows::Forms::Label^  zimnum1;
private: System::Windows::Forms::Label^  zimnum2;
private: System::Windows::Forms::Label^  label73;
private: System::Windows::Forms::Label^  barnaz3;
private: System::Windows::Forms::Label^  label70;
private: System::Windows::Forms::Label^  label69;
private: System::Windows::Forms::Label^  label66;
private: System::Windows::Forms::Label^  zimnaz1;
private: System::Windows::Forms::Label^  zimnum3;
private: System::Windows::Forms::Label^  label83;
private: System::Windows::Forms::Label^  zim3;
private: System::Windows::Forms::Label^  zimnaz3;
private: System::Windows::Forms::Label^  barnum1;
private: System::Windows::Forms::Label^  label45;
private: System::Windows::Forms::Label^  bar1;
private: System::Windows::Forms::Label^  barnaz1;
private: System::Windows::Forms::Label^  label86;
private: System::Windows::Forms::Label^  label85;
private: System::Windows::Forms::Label^  label84;
private: System::Windows::Forms::Label^  barnum3;
private: System::Windows::Forms::Label^  barnum2;
private: System::Windows::Forms::Label^  label91;
private: System::Windows::Forms::Label^  bar3;
private: System::Windows::Forms::Label^  barnaz2;
private: System::Windows::Forms::Label^  label104;
private: System::Windows::Forms::Label^  label103;
private: System::Windows::Forms::Label^  label102;
private: System::Windows::Forms::Label^  val2;
private: System::Windows::Forms::Label^  label108;
private: System::Windows::Forms::Label^  valnum3;
private: System::Windows::Forms::Label^  valnum1;
private: System::Windows::Forms::Label^  valnum2;
private: System::Windows::Forms::Label^  label112;
private: System::Windows::Forms::Label^  val3;
private: System::Windows::Forms::Label^  label114;
private: System::Windows::Forms::Label^  val1;
private: System::Windows::Forms::Label^  valnaz3;
private: System::Windows::Forms::Label^  valnaz1;
private: System::Windows::Forms::Label^  valnaz2;
private: System::Windows::Forms::Label^  st;
private: System::Windows::Forms::ComboBox^  comboBox4;
private: System::Windows::Forms::Label^  label24;
private: System::Windows::Forms::Label^  label30;
private: System::Windows::Forms::TabControl^  tabControl1;
private: System::Windows::Forms::TabPage^  tabPage9;
private: System::Windows::Forms::Button^  new1;
private: System::Windows::Forms::Label^  label41;
private: System::Windows::Forms::Label^  label48;
private: System::Windows::Forms::Label^  label46;
private: System::Windows::Forms::Label^  label40;
private: System::Windows::Forms::Label^  label44;
private: System::Windows::Forms::Label^  label43;
private: System::Windows::Forms::Label^  label23;
private: System::Windows::Forms::Label^  label34;
private: System::Windows::Forms::ListBox^  listBox3;
private: System::Windows::Forms::ListBox^  listBox1;
private: System::Windows::Forms::Label^  label38;
private: System::Windows::Forms::Label^  label35;
private: System::Windows::Forms::TabPage^  tabPage10;
private: System::Windows::Forms::TabPage^  tabPage11;
private: System::Windows::Forms::TabPage^  tabPage12;
private: System::Windows::Forms::Button^  button2;
private: System::Windows::Forms::Label^  label57;
private: System::Windows::Forms::Label^  label60;
private: System::Windows::Forms::Label^  label61;
private: System::Windows::Forms::ListBox^  listBox5;
private: System::Windows::Forms::ListBox^  listBox7;
private: System::Windows::Forms::Button^  button3;
private: System::Windows::Forms::Label^  label76;
private: System::Windows::Forms::Label^  label77;
private: System::Windows::Forms::Label^  label78;
private: System::Windows::Forms::ListBox^  listBox9;
private: System::Windows::Forms::ListBox^  listBox10;
private: System::Windows::Forms::Button^  button4;
private: System::Windows::Forms::Label^  label93;
private: System::Windows::Forms::Label^  label94;
private: System::Windows::Forms::Label^  label95;
private: System::Windows::Forms::ListBox^  listBox11;
private: System::Windows::Forms::ListBox^  listBox12;
private: System::Windows::Forms::ListBox^  listBox13;
private: System::Windows::Forms::Timer^  timer2;
private: System::Windows::Forms::PictureBox^  pictureBox1;
private: System::Windows::Forms::PictureBox^  pictureBox3;
private: System::Windows::Forms::PictureBox^  pictureBox4;
private: System::Windows::Forms::PictureBox^  pictureBox2;
private: System::Windows::Forms::Label^  label99;
private: System::Windows::Forms::Label^  label42;
private: System::Windows::Forms::Label^  label36;
private: System::Windows::Forms::Label^  label47;
private: System::Windows::Forms::Label^  label49;
private: System::Windows::Forms::Label^  label50;
private: System::Windows::Forms::Label^  label51;
private: System::Windows::Forms::Label^  label55;
private: System::Windows::Forms::Label^  label56;
private: System::Windows::Forms::Label^  label62;
private: System::Windows::Forms::Label^  label63;
private: System::Windows::Forms::Label^  label64;
private: System::Windows::Forms::Label^  label65;
private: System::Windows::Forms::Label^  label67;
private: System::Windows::Forms::Label^  label68;
private: System::Windows::Forms::Label^  label71;
private: System::Windows::Forms::Label^  label72;
private: System::Windows::Forms::Label^  label74;
private: System::Windows::Forms::Label^  label75;
private: System::Windows::Forms::Label^  label79;
private: System::Windows::Forms::Label^  label80;
private: System::Windows::Forms::Label^  label81;
private: System::Windows::Forms::Label^  label82;
private: System::Windows::Forms::Label^  label87;
private: System::Windows::Forms::Label^  label88;
private: System::Windows::Forms::Label^  label89;
private: System::Windows::Forms::Label^  label90;
private: System::Windows::Forms::Label^  label92;
private: System::Windows::Forms::Label^  label96;
private: System::Windows::Forms::Label^  label97;
private: System::Windows::Forms::Label^  label98;
private: System::Windows::Forms::Label^  label100;
private: System::Windows::Forms::Label^  label109;
private: System::Windows::Forms::Label^  label117;
private: System::Windows::Forms::ListBox^  listBox2;
private: System::Windows::Forms::ListBox^  listBox4;
private: System::Windows::Forms::Panel^  panel1;
private: System::Windows::Forms::Label^  label106;
private: System::Windows::Forms::Label^  label113;
private: System::Windows::Forms::Label^  label110;
private: System::Windows::Forms::Label^  label107;
private: System::Windows::Forms::Label^  label105;
private: System::Windows::Forms::Button^  button5;
private: System::Windows::Forms::ListBox^  listBox15;
private: System::Windows::Forms::ListBox^  listBox6;
private: System::Windows::Forms::ListBox^  listBox8;
private: System::Windows::Forms::Label^  label158;
private: System::Windows::Forms::Label^  label159;
private: System::Windows::Forms::ListBox^  listBox28;
private: System::Windows::Forms::Label^  label160;
private: System::Windows::Forms::ListBox^  listBox29;
private: System::Windows::Forms::Label^  label161;
private: System::Windows::Forms::Label^  label162;
private: System::Windows::Forms::ListBox^  listBox30;
private: System::Windows::Forms::Label^  label163;
private: System::Windows::Forms::Label^  label164;
private: System::Windows::Forms::ListBox^  listBox31;
private: System::Windows::Forms::Label^  label165;
private: System::Windows::Forms::Panel^  panel5;
private: System::Windows::Forms::Button^  button7;
private: System::Windows::Forms::Label^  label122;
private: System::Windows::Forms::Label^  label123;
private: System::Windows::Forms::Label^  label124;
private: System::Windows::Forms::Label^  label125;
private: System::Windows::Forms::Label^  label126;
private: System::Windows::Forms::Label^  label127;
private: System::Windows::Forms::ListBox^  listBox22;
private: System::Windows::Forms::ListBox^  listBox23;
private: System::Windows::Forms::ListBox^  listBox24;
private: System::Windows::Forms::ListBox^  listBox25;
private: System::Windows::Forms::ListBox^  listBox26;
private: System::Windows::Forms::ListBox^  listBox27;
private: System::Windows::Forms::ListBox^  listBox32;
private: System::Windows::Forms::ListBox^  listBox33;
private: System::Windows::Forms::ListBox^  listBox34;
private: System::Windows::Forms::ListBox^  listBox35;
private: System::Windows::Forms::ListBox^  listBox36;
private: System::Windows::Forms::ListBox^  listBox37;
private: System::Windows::Forms::Label^  label128;
private: System::Windows::Forms::Label^  label129;
private: System::Windows::Forms::Label^  label130;
private: System::Windows::Forms::Label^  label131;
private: System::Windows::Forms::Label^  label132;
private: System::Windows::Forms::Label^  label133;
private: System::Windows::Forms::Label^  label134;
private: System::Windows::Forms::Label^  label135;
private: System::Windows::Forms::Label^  label171;
private: System::Windows::Forms::Label^  label101;
private: System::Windows::Forms::TabControl^  tabControl2;
private: System::Windows::Forms::TabPage^  tabPage2;
private: System::Windows::Forms::Button^  button8;
private: System::Windows::Forms::Label^  label116;
private: System::Windows::Forms::Label^  label118;
private: System::Windows::Forms::Label^  label119;
private: System::Windows::Forms::Label^  label139;
private: System::Windows::Forms::ListBox^  listBox14;
private: System::Windows::Forms::ListBox^  listBox16;
private: System::Windows::Forms::ListBox^  listBox17;
private: System::Windows::Forms::Label^  label140;
private: System::Windows::Forms::Label^  label141;
private: System::Windows::Forms::Label^  label142;
private: System::Windows::Forms::TabPage^  tabPage13;
private: System::Windows::Forms::Label^  label157;
private: System::Windows::Forms::TabPage^  tabPage15;
private: System::Windows::Forms::Label^  label180;
private: System::Windows::Forms::Label^  label181;
private: System::Windows::Forms::Label^  label182;
private: System::Windows::Forms::Label^  label183;
private: System::Windows::Forms::Label^  label184;
private: System::Windows::Forms::Label^  label185;
private: System::Windows::Forms::Label^  label186;
private: System::Windows::Forms::Label^  label187;
private: System::Windows::Forms::Label^  label188;
private: System::Windows::Forms::Label^  label189;
private: System::Windows::Forms::Label^  label190;
private: System::Windows::Forms::Label^  label191;
private: System::Windows::Forms::Label^  label192;
private: System::Windows::Forms::Label^  label193;
private: System::Windows::Forms::Label^  label194;
private: System::Windows::Forms::ListBox^  listBox18;
private: System::Windows::Forms::Label^  label136;
private: System::Windows::Forms::Label^  label111;
private: System::Windows::Forms::Label^  label121;
private: System::Windows::Forms::Label^  label115;
private: System::Windows::Forms::ListBox^  listBox19;
private: System::Windows::Forms::Label^  label120;
private: System::Windows::Forms::Button^  button9;
private: System::Windows::Forms::Label^  label137;
private: System::Windows::Forms::Label^  label138;
private: System::Windows::Forms::Label^  label143;
private: System::Windows::Forms::Label^  label144;
private: System::Windows::Forms::Label^  label145;
private: System::Windows::Forms::Label^  label146;
private: System::Windows::Forms::Label^  label147;
private: System::Windows::Forms::Label^  label148;
private: System::Windows::Forms::ListBox^  listBox20;
private: System::Windows::Forms::ListBox^  listBox21;
private: System::Windows::Forms::ListBox^  listBox38;
private: System::Windows::Forms::ListBox^  listBox39;
private: System::Windows::Forms::ListBox^  listBox40;
private: System::Windows::Forms::Label^  label149;
private: System::Windows::Forms::Label^  label150;
private: System::Windows::Forms::Label^  label151;
private: System::Windows::Forms::Label^  label152;
private: System::Windows::Forms::Button^  button29;
private: System::Windows::Forms::Label^  label153;
private: System::Windows::Forms::Label^  label154;
private: System::Windows::Forms::Label^  label155;
private: System::Windows::Forms::Label^  label156;
private: System::Windows::Forms::Label^  label166;
private: System::Windows::Forms::Label^  label167;
private: System::Windows::Forms::Label^  label168;
private: System::Windows::Forms::Label^  label169;
private: System::Windows::Forms::ListBox^  listBox41;
private: System::Windows::Forms::ListBox^  listBox42;
private: System::Windows::Forms::ListBox^  listBox43;
private: System::Windows::Forms::ListBox^  listBox44;
private: System::Windows::Forms::ListBox^  listBox45;
private: System::Windows::Forms::Label^  label170;
private: System::Windows::Forms::Label^  label172;
private: System::Windows::Forms::Label^  label173;
private: System::Windows::Forms::Label^  label174;
private: System::Windows::Forms::Label^  label176;
private: System::Windows::Forms::ListBox^  listBox46;
private: System::Windows::Forms::Label^  label175;













private: System::Windows::Forms::ImageList^  imageList1;
private: System::Windows::Forms::PictureBox^  ten1;
private: System::Windows::Forms::TabPage^  tabPage14;
private: System::ComponentModel::IContainer^  components;

#pragma endregion


	protected: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->Ù‡ÈÎToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->‚˚ıÓ‰ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ÔÓÏÓ˘¸ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ÛÍÓ‚Ó‰ÒÚ‚ÓœÓÎ¸ÁÓ‚‡ÚÂÎˇToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox8 = (gcnew System::Windows::Forms::PictureBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->pictureBox5 = (gcnew System::Windows::Forms::PictureBox());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->pictureBox7 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox10 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox11 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox12 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox13 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox14 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox15 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox16 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox17 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox18 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox19 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox20 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox21 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox22 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox23 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox24 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox25 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox26 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox27 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox28 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox29 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox30 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox31 = (gcnew System::Windows::Forms::PictureBox());
			this->panel8 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox32 = (gcnew System::Windows::Forms::PictureBox());
			this->button12 = (gcnew System::Windows::Forms::Button());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->panel9 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox33 = (gcnew System::Windows::Forms::PictureBox());
			this->button13 = (gcnew System::Windows::Forms::Button());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->panel10 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox34 = (gcnew System::Windows::Forms::PictureBox());
			this->button14 = (gcnew System::Windows::Forms::Button());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->tabPage4 = (gcnew System::Windows::Forms::TabPage());
			this->panel11 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox35 = (gcnew System::Windows::Forms::PictureBox());
			this->button15 = (gcnew System::Windows::Forms::Button());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->panel12 = (gcnew System::Windows::Forms::Panel());
			this->button16 = (gcnew System::Windows::Forms::Button());
			this->button17 = (gcnew System::Windows::Forms::Button());
			this->pictureBox36 = (gcnew System::Windows::Forms::PictureBox());
			this->button18 = (gcnew System::Windows::Forms::Button());
			this->pictureBox37 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox38 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox39 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox40 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox41 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox42 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox43 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox44 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox45 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox46 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox47 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox48 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox49 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox50 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox51 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox52 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox53 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox54 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox55 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox56 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox57 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox58 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox59 = (gcnew System::Windows::Forms::PictureBox());
			this->panel13 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox60 = (gcnew System::Windows::Forms::PictureBox());
			this->button19 = (gcnew System::Windows::Forms::Button());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->panel14 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox61 = (gcnew System::Windows::Forms::PictureBox());
			this->button20 = (gcnew System::Windows::Forms::Button());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->panel15 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox62 = (gcnew System::Windows::Forms::PictureBox());
			this->button21 = (gcnew System::Windows::Forms::Button());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->panel16 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox63 = (gcnew System::Windows::Forms::PictureBox());
			this->button22 = (gcnew System::Windows::Forms::Button());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->panel17 = (gcnew System::Windows::Forms::Panel());
			this->button23 = (gcnew System::Windows::Forms::Button());
			this->button24 = (gcnew System::Windows::Forms::Button());
			this->pictureBox64 = (gcnew System::Windows::Forms::PictureBox());
			this->button25 = (gcnew System::Windows::Forms::Button());
			this->pictureBox65 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox66 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox67 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox68 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox69 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox70 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox71 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox72 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox73 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox74 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox75 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox76 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox77 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox78 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox79 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox80 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox81 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox82 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox83 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox84 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox85 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox86 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox87 = (gcnew System::Windows::Forms::PictureBox());
			this->panel18 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox88 = (gcnew System::Windows::Forms::PictureBox());
			this->button26 = (gcnew System::Windows::Forms::Button());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->panel19 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox89 = (gcnew System::Windows::Forms::PictureBox());
			this->button27 = (gcnew System::Windows::Forms::Button());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->panel20 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox90 = (gcnew System::Windows::Forms::PictureBox());
			this->button28 = (gcnew System::Windows::Forms::Button());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->Imitation = (gcnew System::Windows::Forms::TabPage());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->st = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->button30 = (gcnew System::Windows::Forms::Button());
			this->checkBox4 = (gcnew System::Windows::Forms::CheckBox());
			this->label30 = (gcnew System::Windows::Forms::Label());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->label99 = (gcnew System::Windows::Forms::Label());
			this->label24 = (gcnew System::Windows::Forms::Label());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->checkBox3 = (gcnew System::Windows::Forms::CheckBox());
			this->surname = (gcnew System::Windows::Forms::TextBox());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label25 = (gcnew System::Windows::Forms::Label());
			this->label26 = (gcnew System::Windows::Forms::Label());
			this->comboBox4 = (gcnew System::Windows::Forms::ComboBox());
			this->panel22 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox92 = (gcnew System::Windows::Forms::PictureBox());
			this->buttonval = (gcnew System::Windows::Forms::Button());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->panel23 = (gcnew System::Windows::Forms::Panel());
			this->button31 = (gcnew System::Windows::Forms::Button());
			this->button32 = (gcnew System::Windows::Forms::Button());
			this->ten1 = (gcnew System::Windows::Forms::PictureBox());
			this->sec0 = (gcnew System::Windows::Forms::PictureBox());
			this->ten_hour = (gcnew System::Windows::Forms::PictureBox());
			this->hour2 = (gcnew System::Windows::Forms::PictureBox());
			this->panel24 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox117 = (gcnew System::Windows::Forms::PictureBox());
			this->buttonbar = (gcnew System::Windows::Forms::Button());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->panel25 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox118 = (gcnew System::Windows::Forms::PictureBox());
			this->buttonzim = (gcnew System::Windows::Forms::Button());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->panel21 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox91 = (gcnew System::Windows::Forms::PictureBox());
			this->buttoncom = (gcnew System::Windows::Forms::Button());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->hour4 = (gcnew System::Windows::Forms::PictureBox());
			this->tabImitation = (gcnew System::Windows::Forms::TabControl());
			this->tabPage8 = (gcnew System::Windows::Forms::TabPage());
			this->label31 = (gcnew System::Windows::Forms::Label());
			this->label32 = (gcnew System::Windows::Forms::Label());
			this->label29 = (gcnew System::Windows::Forms::Label());
			this->label28 = (gcnew System::Windows::Forms::Label());
			this->label27 = (gcnew System::Windows::Forms::Label());
			this->valnum3 = (gcnew System::Windows::Forms::Label());
			this->comnum3 = (gcnew System::Windows::Forms::Label());
			this->valnum1 = (gcnew System::Windows::Forms::Label());
			this->barnum3 = (gcnew System::Windows::Forms::Label());
			this->zimnum3 = (gcnew System::Windows::Forms::Label());
			this->zimnum1 = (gcnew System::Windows::Forms::Label());
			this->comnum2 = (gcnew System::Windows::Forms::Label());
			this->valnum2 = (gcnew System::Windows::Forms::Label());
			this->barnum1 = (gcnew System::Windows::Forms::Label());
			this->barnum2 = (gcnew System::Windows::Forms::Label());
			this->zimnum2 = (gcnew System::Windows::Forms::Label());
			this->comnum1 = (gcnew System::Windows::Forms::Label());
			this->label54 = (gcnew System::Windows::Forms::Label());
			this->zim2 = (gcnew System::Windows::Forms::Label());
			this->label59 = (gcnew System::Windows::Forms::Label());
			this->label45 = (gcnew System::Windows::Forms::Label());
			this->label53 = (gcnew System::Windows::Forms::Label());
			this->label83 = (gcnew System::Windows::Forms::Label());
			this->label112 = (gcnew System::Windows::Forms::Label());
			this->label108 = (gcnew System::Windows::Forms::Label());
			this->val3 = (gcnew System::Windows::Forms::Label());
			this->val2 = (gcnew System::Windows::Forms::Label());
			this->label52 = (gcnew System::Windows::Forms::Label());
			this->zim3 = (gcnew System::Windows::Forms::Label());
			this->label91 = (gcnew System::Windows::Forms::Label());
			this->bar3 = (gcnew System::Windows::Forms::Label());
			this->label73 = (gcnew System::Windows::Forms::Label());
			this->bar1 = (gcnew System::Windows::Forms::Label());
			this->com3 = (gcnew System::Windows::Forms::Label());
			this->com2 = (gcnew System::Windows::Forms::Label());
			this->zim1 = (gcnew System::Windows::Forms::Label());
			this->bar2 = (gcnew System::Windows::Forms::Label());
			this->label114 = (gcnew System::Windows::Forms::Label());
			this->val1 = (gcnew System::Windows::Forms::Label());
			this->label37 = (gcnew System::Windows::Forms::Label());
			this->com1 = (gcnew System::Windows::Forms::Label());
			this->label104 = (gcnew System::Windows::Forms::Label());
			this->label103 = (gcnew System::Windows::Forms::Label());
			this->label102 = (gcnew System::Windows::Forms::Label());
			this->barnaz1 = (gcnew System::Windows::Forms::Label());
			this->comnaz3 = (gcnew System::Windows::Forms::Label());
			this->valnaz3 = (gcnew System::Windows::Forms::Label());
			this->barnaz2 = (gcnew System::Windows::Forms::Label());
			this->valnaz1 = (gcnew System::Windows::Forms::Label());
			this->barnaz3 = (gcnew System::Windows::Forms::Label());
			this->label70 = (gcnew System::Windows::Forms::Label());
			this->label69 = (gcnew System::Windows::Forms::Label());
			this->label66 = (gcnew System::Windows::Forms::Label());
			this->comnaz1 = (gcnew System::Windows::Forms::Label());
			this->label58 = (gcnew System::Windows::Forms::Label());
			this->label39 = (gcnew System::Windows::Forms::Label());
			this->zimnaz1 = (gcnew System::Windows::Forms::Label());
			this->zimnaz3 = (gcnew System::Windows::Forms::Label());
			this->label33 = (gcnew System::Windows::Forms::Label());
			this->label86 = (gcnew System::Windows::Forms::Label());
			this->label85 = (gcnew System::Windows::Forms::Label());
			this->label84 = (gcnew System::Windows::Forms::Label());
			this->comnaz2 = (gcnew System::Windows::Forms::Label());
			this->valnaz2 = (gcnew System::Windows::Forms::Label());
			this->zimnaz2 = (gcnew System::Windows::Forms::Label());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->label100 = (gcnew System::Windows::Forms::Label());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage9 = (gcnew System::Windows::Forms::TabPage());
			this->new1 = (gcnew System::Windows::Forms::Button());
			this->label41 = (gcnew System::Windows::Forms::Label());
			this->label48 = (gcnew System::Windows::Forms::Label());
			this->label46 = (gcnew System::Windows::Forms::Label());
			this->label40 = (gcnew System::Windows::Forms::Label());
			this->label159 = (gcnew System::Windows::Forms::Label());
			this->label44 = (gcnew System::Windows::Forms::Label());
			this->label43 = (gcnew System::Windows::Forms::Label());
			this->label42 = (gcnew System::Windows::Forms::Label());
			this->label36 = (gcnew System::Windows::Forms::Label());
			this->label23 = (gcnew System::Windows::Forms::Label());
			this->label34 = (gcnew System::Windows::Forms::Label());
			this->listBox28 = (gcnew System::Windows::Forms::ListBox());
			this->listBox3 = (gcnew System::Windows::Forms::ListBox());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->label158 = (gcnew System::Windows::Forms::Label());
			this->label38 = (gcnew System::Windows::Forms::Label());
			this->label35 = (gcnew System::Windows::Forms::Label());
			this->tabPage10 = (gcnew System::Windows::Forms::TabPage());
			this->label160 = (gcnew System::Windows::Forms::Label());
			this->listBox29 = (gcnew System::Windows::Forms::ListBox());
			this->label161 = (gcnew System::Windows::Forms::Label());
			this->label63 = (gcnew System::Windows::Forms::Label());
			this->label64 = (gcnew System::Windows::Forms::Label());
			this->label47 = (gcnew System::Windows::Forms::Label());
			this->label49 = (gcnew System::Windows::Forms::Label());
			this->label50 = (gcnew System::Windows::Forms::Label());
			this->label51 = (gcnew System::Windows::Forms::Label());
			this->label55 = (gcnew System::Windows::Forms::Label());
			this->label56 = (gcnew System::Windows::Forms::Label());
			this->label62 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label57 = (gcnew System::Windows::Forms::Label());
			this->label60 = (gcnew System::Windows::Forms::Label());
			this->label61 = (gcnew System::Windows::Forms::Label());
			this->listBox5 = (gcnew System::Windows::Forms::ListBox());
			this->listBox7 = (gcnew System::Windows::Forms::ListBox());
			this->tabPage11 = (gcnew System::Windows::Forms::TabPage());
			this->label162 = (gcnew System::Windows::Forms::Label());
			this->listBox30 = (gcnew System::Windows::Forms::ListBox());
			this->label163 = (gcnew System::Windows::Forms::Label());
			this->label65 = (gcnew System::Windows::Forms::Label());
			this->label67 = (gcnew System::Windows::Forms::Label());
			this->label68 = (gcnew System::Windows::Forms::Label());
			this->label71 = (gcnew System::Windows::Forms::Label());
			this->label72 = (gcnew System::Windows::Forms::Label());
			this->label74 = (gcnew System::Windows::Forms::Label());
			this->label75 = (gcnew System::Windows::Forms::Label());
			this->label79 = (gcnew System::Windows::Forms::Label());
			this->label80 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label76 = (gcnew System::Windows::Forms::Label());
			this->label77 = (gcnew System::Windows::Forms::Label());
			this->label78 = (gcnew System::Windows::Forms::Label());
			this->listBox9 = (gcnew System::Windows::Forms::ListBox());
			this->listBox10 = (gcnew System::Windows::Forms::ListBox());
			this->tabPage12 = (gcnew System::Windows::Forms::TabPage());
			this->label164 = (gcnew System::Windows::Forms::Label());
			this->listBox31 = (gcnew System::Windows::Forms::ListBox());
			this->label165 = (gcnew System::Windows::Forms::Label());
			this->label81 = (gcnew System::Windows::Forms::Label());
			this->label98 = (gcnew System::Windows::Forms::Label());
			this->label82 = (gcnew System::Windows::Forms::Label());
			this->label87 = (gcnew System::Windows::Forms::Label());
			this->label88 = (gcnew System::Windows::Forms::Label());
			this->label89 = (gcnew System::Windows::Forms::Label());
			this->label90 = (gcnew System::Windows::Forms::Label());
			this->label92 = (gcnew System::Windows::Forms::Label());
			this->label96 = (gcnew System::Windows::Forms::Label());
			this->label97 = (gcnew System::Windows::Forms::Label());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->label93 = (gcnew System::Windows::Forms::Label());
			this->label94 = (gcnew System::Windows::Forms::Label());
			this->label95 = (gcnew System::Windows::Forms::Label());
			this->listBox11 = (gcnew System::Windows::Forms::ListBox());
			this->listBox12 = (gcnew System::Windows::Forms::ListBox());
			this->listBox13 = (gcnew System::Windows::Forms::ListBox());
			this->tabPage6 = (gcnew System::Windows::Forms::TabPage());
			this->label171 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->listBox15 = (gcnew System::Windows::Forms::ListBox());
			this->listBox6 = (gcnew System::Windows::Forms::ListBox());
			this->listBox2 = (gcnew System::Windows::Forms::ListBox());
			this->listBox8 = (gcnew System::Windows::Forms::ListBox());
			this->listBox4 = (gcnew System::Windows::Forms::ListBox());
			this->label106 = (gcnew System::Windows::Forms::Label());
			this->label109 = (gcnew System::Windows::Forms::Label());
			this->label113 = (gcnew System::Windows::Forms::Label());
			this->label110 = (gcnew System::Windows::Forms::Label());
			this->label107 = (gcnew System::Windows::Forms::Label());
			this->label105 = (gcnew System::Windows::Forms::Label());
			this->label117 = (gcnew System::Windows::Forms::Label());
			this->tabPage5 = (gcnew System::Windows::Forms::TabPage());
			this->label101 = (gcnew System::Windows::Forms::Label());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->label122 = (gcnew System::Windows::Forms::Label());
			this->label123 = (gcnew System::Windows::Forms::Label());
			this->label124 = (gcnew System::Windows::Forms::Label());
			this->label125 = (gcnew System::Windows::Forms::Label());
			this->label126 = (gcnew System::Windows::Forms::Label());
			this->label127 = (gcnew System::Windows::Forms::Label());
			this->listBox22 = (gcnew System::Windows::Forms::ListBox());
			this->listBox23 = (gcnew System::Windows::Forms::ListBox());
			this->listBox24 = (gcnew System::Windows::Forms::ListBox());
			this->listBox25 = (gcnew System::Windows::Forms::ListBox());
			this->listBox26 = (gcnew System::Windows::Forms::ListBox());
			this->listBox27 = (gcnew System::Windows::Forms::ListBox());
			this->listBox32 = (gcnew System::Windows::Forms::ListBox());
			this->listBox33 = (gcnew System::Windows::Forms::ListBox());
			this->listBox34 = (gcnew System::Windows::Forms::ListBox());
			this->listBox35 = (gcnew System::Windows::Forms::ListBox());
			this->listBox36 = (gcnew System::Windows::Forms::ListBox());
			this->listBox37 = (gcnew System::Windows::Forms::ListBox());
			this->label128 = (gcnew System::Windows::Forms::Label());
			this->label129 = (gcnew System::Windows::Forms::Label());
			this->label130 = (gcnew System::Windows::Forms::Label());
			this->label131 = (gcnew System::Windows::Forms::Label());
			this->label132 = (gcnew System::Windows::Forms::Label());
			this->label133 = (gcnew System::Windows::Forms::Label());
			this->label134 = (gcnew System::Windows::Forms::Label());
			this->label135 = (gcnew System::Windows::Forms::Label());
			this->tabPage7 = (gcnew System::Windows::Forms::TabPage());
			this->label157 = (gcnew System::Windows::Forms::Label());
			this->tabControl2 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->label116 = (gcnew System::Windows::Forms::Label());
			this->label118 = (gcnew System::Windows::Forms::Label());
			this->label136 = (gcnew System::Windows::Forms::Label());
			this->label111 = (gcnew System::Windows::Forms::Label());
			this->label121 = (gcnew System::Windows::Forms::Label());
			this->label115 = (gcnew System::Windows::Forms::Label());
			this->label119 = (gcnew System::Windows::Forms::Label());
			this->label139 = (gcnew System::Windows::Forms::Label());
			this->listBox14 = (gcnew System::Windows::Forms::ListBox());
			this->listBox19 = (gcnew System::Windows::Forms::ListBox());
			this->listBox18 = (gcnew System::Windows::Forms::ListBox());
			this->listBox16 = (gcnew System::Windows::Forms::ListBox());
			this->listBox17 = (gcnew System::Windows::Forms::ListBox());
			this->label140 = (gcnew System::Windows::Forms::Label());
			this->label120 = (gcnew System::Windows::Forms::Label());
			this->label141 = (gcnew System::Windows::Forms::Label());
			this->label142 = (gcnew System::Windows::Forms::Label());
			this->tabPage13 = (gcnew System::Windows::Forms::TabPage());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->label137 = (gcnew System::Windows::Forms::Label());
			this->label138 = (gcnew System::Windows::Forms::Label());
			this->label143 = (gcnew System::Windows::Forms::Label());
			this->label144 = (gcnew System::Windows::Forms::Label());
			this->label145 = (gcnew System::Windows::Forms::Label());
			this->label146 = (gcnew System::Windows::Forms::Label());
			this->label147 = (gcnew System::Windows::Forms::Label());
			this->label148 = (gcnew System::Windows::Forms::Label());
			this->listBox20 = (gcnew System::Windows::Forms::ListBox());
			this->listBox21 = (gcnew System::Windows::Forms::ListBox());
			this->listBox38 = (gcnew System::Windows::Forms::ListBox());
			this->listBox39 = (gcnew System::Windows::Forms::ListBox());
			this->listBox40 = (gcnew System::Windows::Forms::ListBox());
			this->label149 = (gcnew System::Windows::Forms::Label());
			this->label150 = (gcnew System::Windows::Forms::Label());
			this->label151 = (gcnew System::Windows::Forms::Label());
			this->label152 = (gcnew System::Windows::Forms::Label());
			this->tabPage15 = (gcnew System::Windows::Forms::TabPage());
			this->button29 = (gcnew System::Windows::Forms::Button());
			this->label153 = (gcnew System::Windows::Forms::Label());
			this->label154 = (gcnew System::Windows::Forms::Label());
			this->label176 = (gcnew System::Windows::Forms::Label());
			this->label155 = (gcnew System::Windows::Forms::Label());
			this->label156 = (gcnew System::Windows::Forms::Label());
			this->label166 = (gcnew System::Windows::Forms::Label());
			this->label167 = (gcnew System::Windows::Forms::Label());
			this->label168 = (gcnew System::Windows::Forms::Label());
			this->label169 = (gcnew System::Windows::Forms::Label());
			this->listBox41 = (gcnew System::Windows::Forms::ListBox());
			this->listBox46 = (gcnew System::Windows::Forms::ListBox());
			this->listBox42 = (gcnew System::Windows::Forms::ListBox());
			this->listBox43 = (gcnew System::Windows::Forms::ListBox());
			this->listBox44 = (gcnew System::Windows::Forms::ListBox());
			this->listBox45 = (gcnew System::Windows::Forms::ListBox());
			this->label170 = (gcnew System::Windows::Forms::Label());
			this->label175 = (gcnew System::Windows::Forms::Label());
			this->label172 = (gcnew System::Windows::Forms::Label());
			this->label173 = (gcnew System::Windows::Forms::Label());
			this->label174 = (gcnew System::Windows::Forms::Label());
			this->label180 = (gcnew System::Windows::Forms::Label());
			this->label181 = (gcnew System::Windows::Forms::Label());
			this->label182 = (gcnew System::Windows::Forms::Label());
			this->label183 = (gcnew System::Windows::Forms::Label());
			this->label184 = (gcnew System::Windows::Forms::Label());
			this->label185 = (gcnew System::Windows::Forms::Label());
			this->label186 = (gcnew System::Windows::Forms::Label());
			this->label187 = (gcnew System::Windows::Forms::Label());
			this->label188 = (gcnew System::Windows::Forms::Label());
			this->label189 = (gcnew System::Windows::Forms::Label());
			this->label190 = (gcnew System::Windows::Forms::Label());
			this->label191 = (gcnew System::Windows::Forms::Label());
			this->label192 = (gcnew System::Windows::Forms::Label());
			this->label193 = (gcnew System::Windows::Forms::Label());
			this->label194 = (gcnew System::Windows::Forms::Label());
			this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->imageList1 = (gcnew System::Windows::Forms::ImageList(this->components));
			this->tabPage14 = (gcnew System::Windows::Forms::TabPage());
			this->menuStrip1->SuspendLayout();
			this->tabPage3->SuspendLayout();
			this->panel3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox8))->BeginInit();
			this->panel4->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox7))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox10))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox11))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox12))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox13))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox14))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox15))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox16))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox17))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox18))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox19))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox20))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox21))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox22))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox23))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox24))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox25))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox26))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox27))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox28))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox29))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox30))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox31))->BeginInit();
			this->panel8->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox32))->BeginInit();
			this->panel9->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox33))->BeginInit();
			this->panel10->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox34))->BeginInit();
			this->panel11->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox35))->BeginInit();
			this->panel12->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox36))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox37))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox38))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox39))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox40))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox41))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox42))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox43))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox44))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox45))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox46))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox47))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox48))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox49))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox50))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox51))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox52))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox53))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox54))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox55))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox56))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox57))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox58))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox59))->BeginInit();
			this->panel13->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox60))->BeginInit();
			this->panel14->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox61))->BeginInit();
			this->panel15->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox62))->BeginInit();
			this->panel16->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox63))->BeginInit();
			this->panel17->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox64))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox65))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox66))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox67))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox68))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox69))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox70))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox71))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox72))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox73))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox74))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox75))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox76))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox77))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox78))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox79))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox80))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox81))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox82))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox83))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox84))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox85))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox86))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox87))->BeginInit();
			this->panel18->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox88))->BeginInit();
			this->panel19->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox89))->BeginInit();
			this->panel20->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox90))->BeginInit();
			this->Imitation->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->panel2->SuspendLayout();
			this->panel22->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox92))->BeginInit();
			this->panel23->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->ten1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->sec0))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->ten_hour))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->hour2))->BeginInit();
			this->panel24->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox117))->BeginInit();
			this->panel25->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox118))->BeginInit();
			this->panel21->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox91))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->hour4))->BeginInit();
			this->tabImitation->SuspendLayout();
			this->tabPage8->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->tabControl1->SuspendLayout();
			this->tabPage9->SuspendLayout();
			this->tabPage10->SuspendLayout();
			this->tabPage11->SuspendLayout();
			this->tabPage12->SuspendLayout();
			this->tabPage6->SuspendLayout();
			this->panel1->SuspendLayout();
			this->tabPage5->SuspendLayout();
			this->panel5->SuspendLayout();
			this->tabPage7->SuspendLayout();
			this->tabControl2->SuspendLayout();
			this->tabPage2->SuspendLayout();
			this->tabPage13->SuspendLayout();
			this->tabPage15->SuspendLayout();
			this->SuspendLayout();
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->ForeColor = System::Drawing::SystemColors::ControlText;
			this->label4->Location = System::Drawing::Point(22, 121);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(13, 13);
			this->label4->TabIndex = 5;
			this->label4->Text = L"2";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->ForeColor = System::Drawing::SystemColors::ControlText;
			this->label3->Location = System::Drawing::Point(22, 88);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(13, 13);
			this->label3->TabIndex = 4;
			this->label3->Text = L"1";
			// 
			// Ù‡ÈÎToolStripMenuItem
			// 
			this->Ù‡ÈÎToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->‚˚ıÓ‰ToolStripMenuItem});
			this->Ù‡ÈÎToolStripMenuItem->Name = L"Ù‡ÈÎToolStripMenuItem";
			this->Ù‡ÈÎToolStripMenuItem->Size = System::Drawing::Size(56, 21);
			this->Ù‡ÈÎToolStripMenuItem->Text = L"‘‡ÈÎ";
			// 
			// ‚˚ıÓ‰ToolStripMenuItem
			// 
			this->‚˚ıÓ‰ToolStripMenuItem->Name = L"‚˚ıÓ‰ToolStripMenuItem";
			this->‚˚ıÓ‰ToolStripMenuItem->Size = System::Drawing::Size(121, 22);
			this->‚˚ıÓ‰ToolStripMenuItem->Text = L"¬˚ıÓ‰";
			// 
			// ÔÓÏÓ˘¸ToolStripMenuItem
			// 
			this->ÔÓÏÓ˘¸ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->ÛÍÓ‚Ó‰ÒÚ‚ÓœÓÎ¸ÁÓ‚‡ÚÂÎˇToolStripMenuItem});
			this->ÔÓÏÓ˘¸ToolStripMenuItem->Name = L"ÔÓÏÓ˘¸ToolStripMenuItem";
			this->ÔÓÏÓ˘¸ToolStripMenuItem->Size = System::Drawing::Size(74, 21);
			this->ÔÓÏÓ˘¸ToolStripMenuItem->Text = L"œÓÏÓ˘¸";
			// 
			// ÛÍÓ‚Ó‰ÒÚ‚ÓœÓÎ¸ÁÓ‚‡ÚÂÎˇToolStripMenuItem
			// 
			this->ÛÍÓ‚Ó‰ÒÚ‚ÓœÓÎ¸ÁÓ‚‡ÚÂÎˇToolStripMenuItem->Name = L"ÛÍÓ‚Ó‰ÒÚ‚ÓœÓÎ¸ÁÓ‚‡ÚÂÎˇToolStripMenuItem";
			this->ÛÍÓ‚Ó‰ÒÚ‚ÓœÓÎ¸ÁÓ‚‡ÚÂÎˇToolStripMenuItem->Size = System::Drawing::Size(292, 22);
			this->ÛÍÓ‚Ó‰ÒÚ‚ÓœÓÎ¸ÁÓ‚‡ÚÂÎˇToolStripMenuItem->Text = L"–ÛÍÓ‚Ó‰ÒÚ‚Ó ÔÓÎ¸ÁÓ‚‡ÚÂÎˇ";
			this->ÛÍÓ‚Ó‰ÒÚ‚ÓœÓÎ¸ÁÓ‚‡ÚÂÎˇToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::ÛÍÓ‚Ó‰ÒÚ‚ÓœÓÎ¸ÁÓ‚‡ÚÂÎˇToolStripMenuItem_Click);
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::Color::LightSteelBlue;
			this->menuStrip1->Font = (gcnew System::Drawing::Font(L"Courier New", 11));
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->Ù‡ÈÎToolStripMenuItem, 
				this->ÔÓÏÓ˘¸ToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(969, 25);
			this->menuStrip1->TabIndex = 17;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// timer1
			// 
			this->timer1->Interval = 1000;
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// tabPage3
			// 
			this->tabPage3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(187)), static_cast<System::Int32>(static_cast<System::Byte>(221)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->tabPage3->Controls->Add(this->panel3);
			this->tabPage3->Controls->Add(this->panel4);
			this->tabPage3->Controls->Add(this->panel8);
			this->tabPage3->Controls->Add(this->panel9);
			this->tabPage3->Controls->Add(this->panel10);
			this->tabPage3->Location = System::Drawing::Point(4, 25);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Padding = System::Windows::Forms::Padding(3);
			this->tabPage3->Size = System::Drawing::Size(1008, 620);
			this->tabPage3->TabIndex = 1;
			this->tabPage3->Text = L"tabPage2";
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(223)), 
				static_cast<System::Int32>(static_cast<System::Byte>(239)));
			this->panel3->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel3->Controls->Add(this->pictureBox8);
			this->panel3->Controls->Add(this->button1);
			this->panel3->Controls->Add(this->label5);
			this->panel3->ForeColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->panel3->Location = System::Drawing::Point(470, 505);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(282, 109);
			this->panel3->TabIndex = 22;
			// 
			// pictureBox8
			// 
			this->pictureBox8->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox8.Image")));
			this->pictureBox8->Location = System::Drawing::Point(144, 8);
			this->pictureBox8->Name = L"pictureBox8";
			this->pictureBox8->Size = System::Drawing::Size(127, 94);
			this->pictureBox8->TabIndex = 6;
			this->pictureBox8->TabStop = false;
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(187)), static_cast<System::Int32>(static_cast<System::Byte>(221)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->button1->CausesValidation = false;
			this->button1->Font = (gcnew System::Drawing::Font(L"Courier New", 11, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->button1->ForeColor = System::Drawing::Color::Black;
			this->button1->Location = System::Drawing::Point(8, 57);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(127, 28);
			this->button1->TabIndex = 9;
			this->button1->Text = L" ÛÔËÚ¸ ·ËÎÂÚ";
			this->button1->UseVisualStyleBackColor = false;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label5->Font = (gcnew System::Drawing::Font(L"Courier New", 18, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)), 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->label5->ForeColor = System::Drawing::Color::Black;
			this->label5->Location = System::Drawing::Point(9, 8);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(126, 30);
			this->label5->TabIndex = 16;
			this->label5->Text = L"¬‡Î¸ÍÓ‚Ó";
			// 
			// panel4
			// 
			this->panel4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(223)), 
				static_cast<System::Int32>(static_cast<System::Byte>(239)));
			this->panel4->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel4->Controls->Add(this->button6);
			this->panel4->Controls->Add(this->button10);
			this->panel4->Controls->Add(this->pictureBox5);
			this->panel4->Controls->Add(this->button11);
			this->panel4->Controls->Add(this->pictureBox7);
			this->panel4->Controls->Add(this->pictureBox10);
			this->panel4->Controls->Add(this->pictureBox11);
			this->panel4->Controls->Add(this->pictureBox12);
			this->panel4->Controls->Add(this->pictureBox13);
			this->panel4->Controls->Add(this->pictureBox14);
			this->panel4->Controls->Add(this->pictureBox15);
			this->panel4->Controls->Add(this->pictureBox16);
			this->panel4->Controls->Add(this->pictureBox17);
			this->panel4->Controls->Add(this->pictureBox18);
			this->panel4->Controls->Add(this->pictureBox19);
			this->panel4->Controls->Add(this->pictureBox20);
			this->panel4->Controls->Add(this->pictureBox21);
			this->panel4->Controls->Add(this->pictureBox22);
			this->panel4->Controls->Add(this->pictureBox23);
			this->panel4->Controls->Add(this->pictureBox24);
			this->panel4->Controls->Add(this->pictureBox25);
			this->panel4->Controls->Add(this->pictureBox26);
			this->panel4->Controls->Add(this->pictureBox27);
			this->panel4->Controls->Add(this->pictureBox28);
			this->panel4->Controls->Add(this->pictureBox29);
			this->panel4->Controls->Add(this->pictureBox30);
			this->panel4->Controls->Add(this->pictureBox31);
			this->panel4->ForeColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->panel4->Location = System::Drawing::Point(767, 9);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(225, 192);
			this->panel4->TabIndex = 19;
			// 
			// button6
			// 
			this->button6->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(187)), static_cast<System::Int32>(static_cast<System::Byte>(221)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->button6->CausesValidation = false;
			this->button6->Font = (gcnew System::Drawing::Font(L"Courier New", 10, System::Drawing::FontStyle::Bold));
			this->button6->ForeColor = System::Drawing::Color::Black;
			this->button6->Location = System::Drawing::Point(157, 120);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(56, 34);
			this->button6->TabIndex = 41;
			this->button6->Text = L"¬˚ıÓ‰";
			this->button6->UseVisualStyleBackColor = false;
			// 
			// button10
			// 
			this->button10->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(187)), static_cast<System::Int32>(static_cast<System::Byte>(221)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->button10->CausesValidation = false;
			this->button10->Font = (gcnew System::Drawing::Font(L"Courier New", 11, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->button10->ForeColor = System::Drawing::Color::Black;
			this->button10->Location = System::Drawing::Point(96, 120);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(55, 34);
			this->button10->TabIndex = 40;
			this->button10->Text = L"—ÚÓÔ";
			this->button10->UseVisualStyleBackColor = false;
			// 
			// pictureBox5
			// 
			this->pictureBox5->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox5.Image")));
			this->pictureBox5->Location = System::Drawing::Point(173, 10);
			this->pictureBox5->Name = L"pictureBox5";
			this->pictureBox5->Size = System::Drawing::Size(25, 44);
			this->pictureBox5->TabIndex = 39;
			this->pictureBox5->TabStop = false;
			this->pictureBox5->Visible = false;
			// 
			// button11
			// 
			this->button11->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(187)), static_cast<System::Int32>(static_cast<System::Byte>(221)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->button11->CausesValidation = false;
			this->button11->Font = (gcnew System::Drawing::Font(L"Courier New", 11, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->button11->ForeColor = System::Drawing::Color::Black;
			this->button11->Location = System::Drawing::Point(35, 120);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(55, 34);
			this->button11->TabIndex = 9;
			this->button11->Text = L"œÛÒÍ";
			this->button11->UseVisualStyleBackColor = false;
			// 
			// pictureBox7
			// 
			this->pictureBox7->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox7.Image")));
			this->pictureBox7->Location = System::Drawing::Point(80, 10);
			this->pictureBox7->Name = L"pictureBox7";
			this->pictureBox7->Size = System::Drawing::Size(25, 44);
			this->pictureBox7->TabIndex = 38;
			this->pictureBox7->TabStop = false;
			// 
			// pictureBox10
			// 
			this->pictureBox10->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox10.Image")));
			this->pictureBox10->Location = System::Drawing::Point(173, 10);
			this->pictureBox10->Name = L"pictureBox10";
			this->pictureBox10->Size = System::Drawing::Size(25, 44);
			this->pictureBox10->TabIndex = 25;
			this->pictureBox10->TabStop = false;
			// 
			// pictureBox11
			// 
			this->pictureBox11->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox11.Image")));
			this->pictureBox11->Location = System::Drawing::Point(173, 10);
			this->pictureBox11->Name = L"pictureBox11";
			this->pictureBox11->Size = System::Drawing::Size(25, 44);
			this->pictureBox11->TabIndex = 37;
			this->pictureBox11->TabStop = false;
			// 
			// pictureBox12
			// 
			this->pictureBox12->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox12.Image")));
			this->pictureBox12->Location = System::Drawing::Point(80, 10);
			this->pictureBox12->Name = L"pictureBox12";
			this->pictureBox12->Size = System::Drawing::Size(25, 44);
			this->pictureBox12->TabIndex = 36;
			this->pictureBox12->TabStop = false;
			// 
			// pictureBox13
			// 
			this->pictureBox13->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox13.Image")));
			this->pictureBox13->Location = System::Drawing::Point(173, 10);
			this->pictureBox13->Name = L"pictureBox13";
			this->pictureBox13->Size = System::Drawing::Size(25, 44);
			this->pictureBox13->TabIndex = 35;
			this->pictureBox13->TabStop = false;
			// 
			// pictureBox14
			// 
			this->pictureBox14->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox14.Image")));
			this->pictureBox14->InitialImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox14.InitialImage")));
			this->pictureBox14->Location = System::Drawing::Point(173, 10);
			this->pictureBox14->Name = L"pictureBox14";
			this->pictureBox14->Size = System::Drawing::Size(25, 44);
			this->pictureBox14->TabIndex = 34;
			this->pictureBox14->TabStop = false;
			// 
			// pictureBox15
			// 
			this->pictureBox15->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox15.Image")));
			this->pictureBox15->Location = System::Drawing::Point(142, 10);
			this->pictureBox15->Name = L"pictureBox15";
			this->pictureBox15->Size = System::Drawing::Size(25, 44);
			this->pictureBox15->TabIndex = 33;
			this->pictureBox15->TabStop = false;
			// 
			// pictureBox16
			// 
			this->pictureBox16->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox16.Image")));
			this->pictureBox16->Location = System::Drawing::Point(142, 10);
			this->pictureBox16->Name = L"pictureBox16";
			this->pictureBox16->Size = System::Drawing::Size(25, 44);
			this->pictureBox16->TabIndex = 32;
			this->pictureBox16->TabStop = false;
			// 
			// pictureBox17
			// 
			this->pictureBox17->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox17.Image")));
			this->pictureBox17->Location = System::Drawing::Point(142, 10);
			this->pictureBox17->Name = L"pictureBox17";
			this->pictureBox17->Size = System::Drawing::Size(25, 44);
			this->pictureBox17->TabIndex = 31;
			this->pictureBox17->TabStop = false;
			// 
			// pictureBox18
			// 
			this->pictureBox18->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox18.Image")));
			this->pictureBox18->Location = System::Drawing::Point(142, 10);
			this->pictureBox18->Name = L"pictureBox18";
			this->pictureBox18->Size = System::Drawing::Size(25, 44);
			this->pictureBox18->TabIndex = 30;
			this->pictureBox18->TabStop = false;
			// 
			// pictureBox19
			// 
			this->pictureBox19->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox19.Image")));
			this->pictureBox19->InitialImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox19.InitialImage")));
			this->pictureBox19->Location = System::Drawing::Point(142, 10);
			this->pictureBox19->Name = L"pictureBox19";
			this->pictureBox19->Size = System::Drawing::Size(25, 44);
			this->pictureBox19->TabIndex = 29;
			this->pictureBox19->TabStop = false;
			// 
			// pictureBox20
			// 
			this->pictureBox20->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox20.Image")));
			this->pictureBox20->Location = System::Drawing::Point(142, 10);
			this->pictureBox20->Name = L"pictureBox20";
			this->pictureBox20->Size = System::Drawing::Size(25, 44);
			this->pictureBox20->TabIndex = 28;
			this->pictureBox20->TabStop = false;
			// 
			// pictureBox21
			// 
			this->pictureBox21->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox21.Image")));
			this->pictureBox21->Location = System::Drawing::Point(173, 10);
			this->pictureBox21->Name = L"pictureBox21";
			this->pictureBox21->Size = System::Drawing::Size(25, 44);
			this->pictureBox21->TabIndex = 27;
			this->pictureBox21->TabStop = false;
			// 
			// pictureBox22
			// 
			this->pictureBox22->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox22.Image")));
			this->pictureBox22->Location = System::Drawing::Point(173, 10);
			this->pictureBox22->Name = L"pictureBox22";
			this->pictureBox22->Size = System::Drawing::Size(25, 44);
			this->pictureBox22->TabIndex = 26;
			this->pictureBox22->TabStop = false;
			// 
			// pictureBox23
			// 
			this->pictureBox23->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox23.Image")));
			this->pictureBox23->Location = System::Drawing::Point(173, 10);
			this->pictureBox23->Name = L"pictureBox23";
			this->pictureBox23->Size = System::Drawing::Size(25, 44);
			this->pictureBox23->TabIndex = 25;
			this->pictureBox23->TabStop = false;
			// 
			// pictureBox24
			// 
			this->pictureBox24->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox24.Image")));
			this->pictureBox24->Location = System::Drawing::Point(80, 10);
			this->pictureBox24->Name = L"pictureBox24";
			this->pictureBox24->Size = System::Drawing::Size(25, 44);
			this->pictureBox24->TabIndex = 24;
			this->pictureBox24->TabStop = false;
			// 
			// pictureBox25
			// 
			this->pictureBox25->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox25.Image")));
			this->pictureBox25->Location = System::Drawing::Point(80, 10);
			this->pictureBox25->Name = L"pictureBox25";
			this->pictureBox25->Size = System::Drawing::Size(25, 44);
			this->pictureBox25->TabIndex = 23;
			this->pictureBox25->TabStop = false;
			// 
			// pictureBox26
			// 
			this->pictureBox26->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox26.Image")));
			this->pictureBox26->Location = System::Drawing::Point(173, 10);
			this->pictureBox26->Name = L"pictureBox26";
			this->pictureBox26->Size = System::Drawing::Size(25, 44);
			this->pictureBox26->TabIndex = 22;
			this->pictureBox26->TabStop = false;
			// 
			// pictureBox27
			// 
			this->pictureBox27->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox27.Image")));
			this->pictureBox27->Location = System::Drawing::Point(80, 10);
			this->pictureBox27->Name = L"pictureBox27";
			this->pictureBox27->Size = System::Drawing::Size(25, 44);
			this->pictureBox27->TabIndex = 21;
			this->pictureBox27->TabStop = false;
			// 
			// pictureBox28
			// 
			this->pictureBox28->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox28.Image")));
			this->pictureBox28->Location = System::Drawing::Point(173, 10);
			this->pictureBox28->Name = L"pictureBox28";
			this->pictureBox28->Size = System::Drawing::Size(25, 44);
			this->pictureBox28->TabIndex = 20;
			this->pictureBox28->TabStop = false;
			// 
			// pictureBox29
			// 
			this->pictureBox29->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox29.Image")));
			this->pictureBox29->InitialImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox29.InitialImage")));
			this->pictureBox29->Location = System::Drawing::Point(49, 10);
			this->pictureBox29->Name = L"pictureBox29";
			this->pictureBox29->Size = System::Drawing::Size(25, 44);
			this->pictureBox29->TabIndex = 19;
			this->pictureBox29->TabStop = false;
			// 
			// pictureBox30
			// 
			this->pictureBox30->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox30.Image")));
			this->pictureBox30->Location = System::Drawing::Point(80, 10);
			this->pictureBox30->Name = L"pictureBox30";
			this->pictureBox30->Size = System::Drawing::Size(25, 44);
			this->pictureBox30->TabIndex = 19;
			this->pictureBox30->TabStop = false;
			// 
			// pictureBox31
			// 
			this->pictureBox31->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox31.Image")));
			this->pictureBox31->Location = System::Drawing::Point(111, 10);
			this->pictureBox31->Name = L"pictureBox31";
			this->pictureBox31->Size = System::Drawing::Size(25, 44);
			this->pictureBox31->TabIndex = 19;
			this->pictureBox31->TabStop = false;
			// 
			// panel8
			// 
			this->panel8->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(223)), 
				static_cast<System::Int32>(static_cast<System::Byte>(239)));
			this->panel8->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel8->Controls->Add(this->pictureBox32);
			this->panel8->Controls->Add(this->button12);
			this->panel8->Controls->Add(this->label6);
			this->panel8->ForeColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->panel8->Location = System::Drawing::Point(8, 9);
			this->panel8->Name = L"panel8";
			this->panel8->Size = System::Drawing::Size(282, 109);
			this->panel8->TabIndex = 6;
			// 
			// pictureBox32
			// 
			this->pictureBox32->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox32.Image")));
			this->pictureBox32->Location = System::Drawing::Point(8, 8);
			this->pictureBox32->Name = L"pictureBox32";
			this->pictureBox32->Size = System::Drawing::Size(127, 94);
			this->pictureBox32->TabIndex = 6;
			this->pictureBox32->TabStop = false;
			// 
			// button12
			// 
			this->button12->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(187)), static_cast<System::Int32>(static_cast<System::Byte>(221)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->button12->CausesValidation = false;
			this->button12->Font = (gcnew System::Drawing::Font(L"Courier New", 11, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->button12->ForeColor = System::Drawing::Color::Black;
			this->button12->Location = System::Drawing::Point(141, 57);
			this->button12->Name = L"button12";
			this->button12->Size = System::Drawing::Size(127, 28);
			this->button12->TabIndex = 9;
			this->button12->Text = L" ÛÔËÚ¸ ·ËÎÂÚ";
			this->button12->UseVisualStyleBackColor = false;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label6->Font = (gcnew System::Drawing::Font(L"Courier New", 18, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)), 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->label6->ForeColor = System::Drawing::Color::Black;
			this->label6->Location = System::Drawing::Point(141, 8);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(126, 30);
			this->label6->TabIndex = 16;
			this->label6->Text = L" ÓÏ‡Ó‚Ó";
			// 
			// panel9
			// 
			this->panel9->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(223)), 
				static_cast<System::Int32>(static_cast<System::Byte>(239)));
			this->panel9->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel9->Controls->Add(this->pictureBox33);
			this->panel9->Controls->Add(this->button13);
			this->panel9->Controls->Add(this->label8);
			this->panel9->ForeColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->panel9->Location = System::Drawing::Point(8, 505);
			this->panel9->Name = L"panel9";
			this->panel9->Size = System::Drawing::Size(282, 109);
			this->panel9->TabIndex = 23;
			// 
			// pictureBox33
			// 
			this->pictureBox33->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox33.Image")));
			this->pictureBox33->Location = System::Drawing::Point(8, 8);
			this->pictureBox33->Name = L"pictureBox33";
			this->pictureBox33->Size = System::Drawing::Size(127, 94);
			this->pictureBox33->TabIndex = 6;
			this->pictureBox33->TabStop = false;
			// 
			// button13
			// 
			this->button13->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(187)), static_cast<System::Int32>(static_cast<System::Byte>(221)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->button13->CausesValidation = false;
			this->button13->Font = (gcnew System::Drawing::Font(L"Courier New", 11, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->button13->ForeColor = System::Drawing::Color::Black;
			this->button13->Location = System::Drawing::Point(141, 57);
			this->button13->Name = L"button13";
			this->button13->Size = System::Drawing::Size(127, 28);
			this->button13->TabIndex = 9;
			this->button13->Text = L" ÛÔËÚ¸ ·ËÎÂÚ";
			this->button13->UseVisualStyleBackColor = false;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label8->Font = (gcnew System::Drawing::Font(L"Courier New", 18, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)), 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->label8->ForeColor = System::Drawing::Color::Black;
			this->label8->Location = System::Drawing::Point(141, 8);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(112, 30);
			this->label8->TabIndex = 16;
			this->label8->Text = L"¡‡Ì‡ÛÎ";
			// 
			// panel10
			// 
			this->panel10->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(223)), 
				static_cast<System::Int32>(static_cast<System::Byte>(239)));
			this->panel10->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel10->Controls->Add(this->pictureBox34);
			this->panel10->Controls->Add(this->button14);
			this->panel10->Controls->Add(this->label10);
			this->panel10->ForeColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->panel10->Location = System::Drawing::Point(470, 9);
			this->panel10->Name = L"panel10";
			this->panel10->Size = System::Drawing::Size(282, 109);
			this->panel10->TabIndex = 21;
			// 
			// pictureBox34
			// 
			this->pictureBox34->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox34.Image")));
			this->pictureBox34->Location = System::Drawing::Point(144, 8);
			this->pictureBox34->Name = L"pictureBox34";
			this->pictureBox34->Size = System::Drawing::Size(127, 94);
			this->pictureBox34->TabIndex = 6;
			this->pictureBox34->TabStop = false;
			// 
			// button14
			// 
			this->button14->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(187)), static_cast<System::Int32>(static_cast<System::Byte>(221)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->button14->CausesValidation = false;
			this->button14->Font = (gcnew System::Drawing::Font(L"Courier New", 11, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->button14->ForeColor = System::Drawing::Color::Black;
			this->button14->Location = System::Drawing::Point(8, 57);
			this->button14->Name = L"button14";
			this->button14->Size = System::Drawing::Size(127, 28);
			this->button14->TabIndex = 9;
			this->button14->Text = L" ÛÔËÚ¸ ·ËÎÂÚ";
			this->button14->UseVisualStyleBackColor = false;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label10->Font = (gcnew System::Drawing::Font(L"Courier New", 18, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)), 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->label10->ForeColor = System::Drawing::Color::Black;
			this->label10->Location = System::Drawing::Point(22, 8);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(98, 30);
			this->label10->TabIndex = 16;
			this->label10->Text = L"«ËÏÌˇˇ";
			// 
			// tabPage4
			// 
			this->tabPage4->Location = System::Drawing::Point(4, 22);
			this->tabPage4->Name = L"tabPage4";
			this->tabPage4->Padding = System::Windows::Forms::Padding(3);
			this->tabPage4->Size = System::Drawing::Size(1008, 623);
			this->tabPage4->TabIndex = 2;
			this->tabPage4->Text = L"tabPage1";
			this->tabPage4->UseVisualStyleBackColor = true;
			// 
			// panel11
			// 
			this->panel11->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(223)), 
				static_cast<System::Int32>(static_cast<System::Byte>(239)));
			this->panel11->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel11->Controls->Add(this->pictureBox35);
			this->panel11->Controls->Add(this->button15);
			this->panel11->Controls->Add(this->label11);
			this->panel11->ForeColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->panel11->Location = System::Drawing::Point(470, 505);
			this->panel11->Name = L"panel11";
			this->panel11->Size = System::Drawing::Size(282, 109);
			this->panel11->TabIndex = 22;
			// 
			// pictureBox35
			// 
			this->pictureBox35->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox35.Image")));
			this->pictureBox35->Location = System::Drawing::Point(144, 8);
			this->pictureBox35->Name = L"pictureBox35";
			this->pictureBox35->Size = System::Drawing::Size(127, 94);
			this->pictureBox35->TabIndex = 6;
			this->pictureBox35->TabStop = false;
			// 
			// button15
			// 
			this->button15->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(187)), static_cast<System::Int32>(static_cast<System::Byte>(221)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->button15->CausesValidation = false;
			this->button15->Font = (gcnew System::Drawing::Font(L"Courier New", 11, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->button15->ForeColor = System::Drawing::Color::Black;
			this->button15->Location = System::Drawing::Point(8, 57);
			this->button15->Name = L"button15";
			this->button15->Size = System::Drawing::Size(127, 28);
			this->button15->TabIndex = 9;
			this->button15->Text = L" ÛÔËÚ¸ ·ËÎÂÚ";
			this->button15->UseVisualStyleBackColor = false;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label11->Font = (gcnew System::Drawing::Font(L"Courier New", 18, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)), 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->label11->ForeColor = System::Drawing::Color::Black;
			this->label11->Location = System::Drawing::Point(9, 8);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(126, 30);
			this->label11->TabIndex = 16;
			this->label11->Text = L"¬‡Î¸ÍÓ‚Ó";
			// 
			// panel12
			// 
			this->panel12->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(223)), 
				static_cast<System::Int32>(static_cast<System::Byte>(239)));
			this->panel12->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel12->Controls->Add(this->button16);
			this->panel12->Controls->Add(this->button17);
			this->panel12->Controls->Add(this->pictureBox36);
			this->panel12->Controls->Add(this->button18);
			this->panel12->Controls->Add(this->pictureBox37);
			this->panel12->Controls->Add(this->pictureBox38);
			this->panel12->Controls->Add(this->pictureBox39);
			this->panel12->Controls->Add(this->pictureBox40);
			this->panel12->Controls->Add(this->pictureBox41);
			this->panel12->Controls->Add(this->pictureBox42);
			this->panel12->Controls->Add(this->pictureBox43);
			this->panel12->Controls->Add(this->pictureBox44);
			this->panel12->Controls->Add(this->pictureBox45);
			this->panel12->Controls->Add(this->pictureBox46);
			this->panel12->Controls->Add(this->pictureBox47);
			this->panel12->Controls->Add(this->pictureBox48);
			this->panel12->Controls->Add(this->pictureBox49);
			this->panel12->Controls->Add(this->pictureBox50);
			this->panel12->Controls->Add(this->pictureBox51);
			this->panel12->Controls->Add(this->pictureBox52);
			this->panel12->Controls->Add(this->pictureBox53);
			this->panel12->Controls->Add(this->pictureBox54);
			this->panel12->Controls->Add(this->pictureBox55);
			this->panel12->Controls->Add(this->pictureBox56);
			this->panel12->Controls->Add(this->pictureBox57);
			this->panel12->Controls->Add(this->pictureBox58);
			this->panel12->Controls->Add(this->pictureBox59);
			this->panel12->ForeColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->panel12->Location = System::Drawing::Point(767, 9);
			this->panel12->Name = L"panel12";
			this->panel12->Size = System::Drawing::Size(225, 192);
			this->panel12->TabIndex = 19;
			// 
			// button16
			// 
			this->button16->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(187)), static_cast<System::Int32>(static_cast<System::Byte>(221)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->button16->CausesValidation = false;
			this->button16->Font = (gcnew System::Drawing::Font(L"Courier New", 10, System::Drawing::FontStyle::Bold));
			this->button16->ForeColor = System::Drawing::Color::Black;
			this->button16->Location = System::Drawing::Point(157, 120);
			this->button16->Name = L"button16";
			this->button16->Size = System::Drawing::Size(56, 34);
			this->button16->TabIndex = 41;
			this->button16->Text = L"¬˚ıÓ‰";
			this->button16->UseVisualStyleBackColor = false;
			// 
			// button17
			// 
			this->button17->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(187)), static_cast<System::Int32>(static_cast<System::Byte>(221)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->button17->CausesValidation = false;
			this->button17->Font = (gcnew System::Drawing::Font(L"Courier New", 11, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->button17->ForeColor = System::Drawing::Color::Black;
			this->button17->Location = System::Drawing::Point(96, 120);
			this->button17->Name = L"button17";
			this->button17->Size = System::Drawing::Size(55, 34);
			this->button17->TabIndex = 40;
			this->button17->Text = L"—ÚÓÔ";
			this->button17->UseVisualStyleBackColor = false;
			// 
			// pictureBox36
			// 
			this->pictureBox36->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox36.Image")));
			this->pictureBox36->Location = System::Drawing::Point(173, 10);
			this->pictureBox36->Name = L"pictureBox36";
			this->pictureBox36->Size = System::Drawing::Size(25, 44);
			this->pictureBox36->TabIndex = 39;
			this->pictureBox36->TabStop = false;
			this->pictureBox36->Visible = false;
			// 
			// button18
			// 
			this->button18->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(187)), static_cast<System::Int32>(static_cast<System::Byte>(221)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->button18->CausesValidation = false;
			this->button18->Font = (gcnew System::Drawing::Font(L"Courier New", 11, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->button18->ForeColor = System::Drawing::Color::Black;
			this->button18->Location = System::Drawing::Point(35, 120);
			this->button18->Name = L"button18";
			this->button18->Size = System::Drawing::Size(55, 34);
			this->button18->TabIndex = 9;
			this->button18->Text = L"œÛÒÍ";
			this->button18->UseVisualStyleBackColor = false;
			// 
			// pictureBox37
			// 
			this->pictureBox37->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox37.Image")));
			this->pictureBox37->Location = System::Drawing::Point(80, 10);
			this->pictureBox37->Name = L"pictureBox37";
			this->pictureBox37->Size = System::Drawing::Size(25, 44);
			this->pictureBox37->TabIndex = 38;
			this->pictureBox37->TabStop = false;
			// 
			// pictureBox38
			// 
			this->pictureBox38->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox38.Image")));
			this->pictureBox38->Location = System::Drawing::Point(173, 10);
			this->pictureBox38->Name = L"pictureBox38";
			this->pictureBox38->Size = System::Drawing::Size(25, 44);
			this->pictureBox38->TabIndex = 25;
			this->pictureBox38->TabStop = false;
			// 
			// pictureBox39
			// 
			this->pictureBox39->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox39.Image")));
			this->pictureBox39->Location = System::Drawing::Point(173, 10);
			this->pictureBox39->Name = L"pictureBox39";
			this->pictureBox39->Size = System::Drawing::Size(25, 44);
			this->pictureBox39->TabIndex = 37;
			this->pictureBox39->TabStop = false;
			// 
			// pictureBox40
			// 
			this->pictureBox40->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox40.Image")));
			this->pictureBox40->Location = System::Drawing::Point(80, 10);
			this->pictureBox40->Name = L"pictureBox40";
			this->pictureBox40->Size = System::Drawing::Size(25, 44);
			this->pictureBox40->TabIndex = 36;
			this->pictureBox40->TabStop = false;
			// 
			// pictureBox41
			// 
			this->pictureBox41->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox41.Image")));
			this->pictureBox41->Location = System::Drawing::Point(173, 10);
			this->pictureBox41->Name = L"pictureBox41";
			this->pictureBox41->Size = System::Drawing::Size(25, 44);
			this->pictureBox41->TabIndex = 35;
			this->pictureBox41->TabStop = false;
			// 
			// pictureBox42
			// 
			this->pictureBox42->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox42.Image")));
			this->pictureBox42->InitialImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox42.InitialImage")));
			this->pictureBox42->Location = System::Drawing::Point(173, 10);
			this->pictureBox42->Name = L"pictureBox42";
			this->pictureBox42->Size = System::Drawing::Size(25, 44);
			this->pictureBox42->TabIndex = 34;
			this->pictureBox42->TabStop = false;
			// 
			// pictureBox43
			// 
			this->pictureBox43->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox43.Image")));
			this->pictureBox43->Location = System::Drawing::Point(142, 10);
			this->pictureBox43->Name = L"pictureBox43";
			this->pictureBox43->Size = System::Drawing::Size(25, 44);
			this->pictureBox43->TabIndex = 33;
			this->pictureBox43->TabStop = false;
			// 
			// pictureBox44
			// 
			this->pictureBox44->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox44.Image")));
			this->pictureBox44->Location = System::Drawing::Point(142, 10);
			this->pictureBox44->Name = L"pictureBox44";
			this->pictureBox44->Size = System::Drawing::Size(25, 44);
			this->pictureBox44->TabIndex = 32;
			this->pictureBox44->TabStop = false;
			// 
			// pictureBox45
			// 
			this->pictureBox45->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox45.Image")));
			this->pictureBox45->Location = System::Drawing::Point(142, 10);
			this->pictureBox45->Name = L"pictureBox45";
			this->pictureBox45->Size = System::Drawing::Size(25, 44);
			this->pictureBox45->TabIndex = 31;
			this->pictureBox45->TabStop = false;
			// 
			// pictureBox46
			// 
			this->pictureBox46->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox46.Image")));
			this->pictureBox46->Location = System::Drawing::Point(142, 10);
			this->pictureBox46->Name = L"pictureBox46";
			this->pictureBox46->Size = System::Drawing::Size(25, 44);
			this->pictureBox46->TabIndex = 30;
			this->pictureBox46->TabStop = false;
			// 
			// pictureBox47
			// 
			this->pictureBox47->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox47.Image")));
			this->pictureBox47->InitialImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox47.InitialImage")));
			this->pictureBox47->Location = System::Drawing::Point(142, 10);
			this->pictureBox47->Name = L"pictureBox47";
			this->pictureBox47->Size = System::Drawing::Size(25, 44);
			this->pictureBox47->TabIndex = 29;
			this->pictureBox47->TabStop = false;
			// 
			// pictureBox48
			// 
			this->pictureBox48->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox48.Image")));
			this->pictureBox48->Location = System::Drawing::Point(142, 10);
			this->pictureBox48->Name = L"pictureBox48";
			this->pictureBox48->Size = System::Drawing::Size(25, 44);
			this->pictureBox48->TabIndex = 28;
			this->pictureBox48->TabStop = false;
			// 
			// pictureBox49
			// 
			this->pictureBox49->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox49.Image")));
			this->pictureBox49->Location = System::Drawing::Point(173, 10);
			this->pictureBox49->Name = L"pictureBox49";
			this->pictureBox49->Size = System::Drawing::Size(25, 44);
			this->pictureBox49->TabIndex = 27;
			this->pictureBox49->TabStop = false;
			// 
			// pictureBox50
			// 
			this->pictureBox50->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox50.Image")));
			this->pictureBox50->Location = System::Drawing::Point(173, 10);
			this->pictureBox50->Name = L"pictureBox50";
			this->pictureBox50->Size = System::Drawing::Size(25, 44);
			this->pictureBox50->TabIndex = 26;
			this->pictureBox50->TabStop = false;
			// 
			// pictureBox51
			// 
			this->pictureBox51->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox51.Image")));
			this->pictureBox51->Location = System::Drawing::Point(173, 10);
			this->pictureBox51->Name = L"pictureBox51";
			this->pictureBox51->Size = System::Drawing::Size(25, 44);
			this->pictureBox51->TabIndex = 25;
			this->pictureBox51->TabStop = false;
			// 
			// pictureBox52
			// 
			this->pictureBox52->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox52.Image")));
			this->pictureBox52->Location = System::Drawing::Point(80, 10);
			this->pictureBox52->Name = L"pictureBox52";
			this->pictureBox52->Size = System::Drawing::Size(25, 44);
			this->pictureBox52->TabIndex = 24;
			this->pictureBox52->TabStop = false;
			// 
			// pictureBox53
			// 
			this->pictureBox53->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox53.Image")));
			this->pictureBox53->Location = System::Drawing::Point(80, 10);
			this->pictureBox53->Name = L"pictureBox53";
			this->pictureBox53->Size = System::Drawing::Size(25, 44);
			this->pictureBox53->TabIndex = 23;
			this->pictureBox53->TabStop = false;
			// 
			// pictureBox54
			// 
			this->pictureBox54->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox54.Image")));
			this->pictureBox54->Location = System::Drawing::Point(173, 10);
			this->pictureBox54->Name = L"pictureBox54";
			this->pictureBox54->Size = System::Drawing::Size(25, 44);
			this->pictureBox54->TabIndex = 22;
			this->pictureBox54->TabStop = false;
			// 
			// pictureBox55
			// 
			this->pictureBox55->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox55.Image")));
			this->pictureBox55->Location = System::Drawing::Point(80, 10);
			this->pictureBox55->Name = L"pictureBox55";
			this->pictureBox55->Size = System::Drawing::Size(25, 44);
			this->pictureBox55->TabIndex = 21;
			this->pictureBox55->TabStop = false;
			// 
			// pictureBox56
			// 
			this->pictureBox56->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox56.Image")));
			this->pictureBox56->Location = System::Drawing::Point(173, 10);
			this->pictureBox56->Name = L"pictureBox56";
			this->pictureBox56->Size = System::Drawing::Size(25, 44);
			this->pictureBox56->TabIndex = 20;
			this->pictureBox56->TabStop = false;
			// 
			// pictureBox57
			// 
			this->pictureBox57->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox57.Image")));
			this->pictureBox57->InitialImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox57.InitialImage")));
			this->pictureBox57->Location = System::Drawing::Point(49, 10);
			this->pictureBox57->Name = L"pictureBox57";
			this->pictureBox57->Size = System::Drawing::Size(25, 44);
			this->pictureBox57->TabIndex = 19;
			this->pictureBox57->TabStop = false;
			// 
			// pictureBox58
			// 
			this->pictureBox58->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox58.Image")));
			this->pictureBox58->Location = System::Drawing::Point(80, 10);
			this->pictureBox58->Name = L"pictureBox58";
			this->pictureBox58->Size = System::Drawing::Size(25, 44);
			this->pictureBox58->TabIndex = 19;
			this->pictureBox58->TabStop = false;
			// 
			// pictureBox59
			// 
			this->pictureBox59->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox59.Image")));
			this->pictureBox59->Location = System::Drawing::Point(111, 10);
			this->pictureBox59->Name = L"pictureBox59";
			this->pictureBox59->Size = System::Drawing::Size(25, 44);
			this->pictureBox59->TabIndex = 19;
			this->pictureBox59->TabStop = false;
			// 
			// panel13
			// 
			this->panel13->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(223)), 
				static_cast<System::Int32>(static_cast<System::Byte>(239)));
			this->panel13->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel13->Controls->Add(this->pictureBox60);
			this->panel13->Controls->Add(this->button19);
			this->panel13->Controls->Add(this->label12);
			this->panel13->ForeColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->panel13->Location = System::Drawing::Point(8, 9);
			this->panel13->Name = L"panel13";
			this->panel13->Size = System::Drawing::Size(282, 109);
			this->panel13->TabIndex = 6;
			// 
			// pictureBox60
			// 
			this->pictureBox60->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox60.Image")));
			this->pictureBox60->Location = System::Drawing::Point(8, 8);
			this->pictureBox60->Name = L"pictureBox60";
			this->pictureBox60->Size = System::Drawing::Size(127, 94);
			this->pictureBox60->TabIndex = 6;
			this->pictureBox60->TabStop = false;
			// 
			// button19
			// 
			this->button19->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(187)), static_cast<System::Int32>(static_cast<System::Byte>(221)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->button19->CausesValidation = false;
			this->button19->Font = (gcnew System::Drawing::Font(L"Courier New", 11, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->button19->ForeColor = System::Drawing::Color::Black;
			this->button19->Location = System::Drawing::Point(141, 57);
			this->button19->Name = L"button19";
			this->button19->Size = System::Drawing::Size(127, 28);
			this->button19->TabIndex = 9;
			this->button19->Text = L" ÛÔËÚ¸ ·ËÎÂÚ";
			this->button19->UseVisualStyleBackColor = false;
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label12->Font = (gcnew System::Drawing::Font(L"Courier New", 18, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)), 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->label12->ForeColor = System::Drawing::Color::Black;
			this->label12->Location = System::Drawing::Point(141, 8);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(126, 30);
			this->label12->TabIndex = 16;
			this->label12->Text = L" ÓÏ‡Ó‚Ó";
			// 
			// panel14
			// 
			this->panel14->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(223)), 
				static_cast<System::Int32>(static_cast<System::Byte>(239)));
			this->panel14->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel14->Controls->Add(this->pictureBox61);
			this->panel14->Controls->Add(this->button20);
			this->panel14->Controls->Add(this->label13);
			this->panel14->ForeColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->panel14->Location = System::Drawing::Point(8, 505);
			this->panel14->Name = L"panel14";
			this->panel14->Size = System::Drawing::Size(282, 109);
			this->panel14->TabIndex = 23;
			// 
			// pictureBox61
			// 
			this->pictureBox61->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox61.Image")));
			this->pictureBox61->Location = System::Drawing::Point(8, 8);
			this->pictureBox61->Name = L"pictureBox61";
			this->pictureBox61->Size = System::Drawing::Size(127, 94);
			this->pictureBox61->TabIndex = 6;
			this->pictureBox61->TabStop = false;
			// 
			// button20
			// 
			this->button20->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(187)), static_cast<System::Int32>(static_cast<System::Byte>(221)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->button20->CausesValidation = false;
			this->button20->Font = (gcnew System::Drawing::Font(L"Courier New", 11, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->button20->ForeColor = System::Drawing::Color::Black;
			this->button20->Location = System::Drawing::Point(141, 57);
			this->button20->Name = L"button20";
			this->button20->Size = System::Drawing::Size(127, 28);
			this->button20->TabIndex = 9;
			this->button20->Text = L" ÛÔËÚ¸ ·ËÎÂÚ";
			this->button20->UseVisualStyleBackColor = false;
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label13->Font = (gcnew System::Drawing::Font(L"Courier New", 18, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)), 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->label13->ForeColor = System::Drawing::Color::Black;
			this->label13->Location = System::Drawing::Point(141, 8);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(112, 30);
			this->label13->TabIndex = 16;
			this->label13->Text = L"¡‡Ì‡ÛÎ";
			// 
			// panel15
			// 
			this->panel15->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(223)), 
				static_cast<System::Int32>(static_cast<System::Byte>(239)));
			this->panel15->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel15->Controls->Add(this->pictureBox62);
			this->panel15->Controls->Add(this->button21);
			this->panel15->Controls->Add(this->label14);
			this->panel15->ForeColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->panel15->Location = System::Drawing::Point(470, 9);
			this->panel15->Name = L"panel15";
			this->panel15->Size = System::Drawing::Size(282, 109);
			this->panel15->TabIndex = 21;
			// 
			// pictureBox62
			// 
			this->pictureBox62->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox62.Image")));
			this->pictureBox62->Location = System::Drawing::Point(144, 8);
			this->pictureBox62->Name = L"pictureBox62";
			this->pictureBox62->Size = System::Drawing::Size(127, 94);
			this->pictureBox62->TabIndex = 6;
			this->pictureBox62->TabStop = false;
			// 
			// button21
			// 
			this->button21->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(187)), static_cast<System::Int32>(static_cast<System::Byte>(221)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->button21->CausesValidation = false;
			this->button21->Font = (gcnew System::Drawing::Font(L"Courier New", 11, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->button21->ForeColor = System::Drawing::Color::Black;
			this->button21->Location = System::Drawing::Point(8, 57);
			this->button21->Name = L"button21";
			this->button21->Size = System::Drawing::Size(127, 28);
			this->button21->TabIndex = 9;
			this->button21->Text = L" ÛÔËÚ¸ ·ËÎÂÚ";
			this->button21->UseVisualStyleBackColor = false;
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label14->Font = (gcnew System::Drawing::Font(L"Courier New", 18, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)), 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->label14->ForeColor = System::Drawing::Color::Black;
			this->label14->Location = System::Drawing::Point(22, 8);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(98, 30);
			this->label14->TabIndex = 16;
			this->label14->Text = L"«ËÏÌˇˇ";
			// 
			// panel16
			// 
			this->panel16->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(223)), 
				static_cast<System::Int32>(static_cast<System::Byte>(239)));
			this->panel16->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel16->Controls->Add(this->pictureBox63);
			this->panel16->Controls->Add(this->button22);
			this->panel16->Controls->Add(this->label15);
			this->panel16->ForeColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->panel16->Location = System::Drawing::Point(470, 505);
			this->panel16->Name = L"panel16";
			this->panel16->Size = System::Drawing::Size(282, 109);
			this->panel16->TabIndex = 22;
			// 
			// pictureBox63
			// 
			this->pictureBox63->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox63.Image")));
			this->pictureBox63->Location = System::Drawing::Point(144, 8);
			this->pictureBox63->Name = L"pictureBox63";
			this->pictureBox63->Size = System::Drawing::Size(127, 94);
			this->pictureBox63->TabIndex = 6;
			this->pictureBox63->TabStop = false;
			// 
			// button22
			// 
			this->button22->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(187)), static_cast<System::Int32>(static_cast<System::Byte>(221)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->button22->CausesValidation = false;
			this->button22->Font = (gcnew System::Drawing::Font(L"Courier New", 11, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->button22->ForeColor = System::Drawing::Color::Black;
			this->button22->Location = System::Drawing::Point(8, 57);
			this->button22->Name = L"button22";
			this->button22->Size = System::Drawing::Size(127, 28);
			this->button22->TabIndex = 9;
			this->button22->Text = L" ÛÔËÚ¸ ·ËÎÂÚ";
			this->button22->UseVisualStyleBackColor = false;
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label15->Font = (gcnew System::Drawing::Font(L"Courier New", 18, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)), 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->label15->ForeColor = System::Drawing::Color::Black;
			this->label15->Location = System::Drawing::Point(9, 8);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(126, 30);
			this->label15->TabIndex = 16;
			this->label15->Text = L"¬‡Î¸ÍÓ‚Ó";
			// 
			// panel17
			// 
			this->panel17->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(223)), 
				static_cast<System::Int32>(static_cast<System::Byte>(239)));
			this->panel17->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel17->Controls->Add(this->button23);
			this->panel17->Controls->Add(this->button24);
			this->panel17->Controls->Add(this->pictureBox64);
			this->panel17->Controls->Add(this->button25);
			this->panel17->Controls->Add(this->pictureBox65);
			this->panel17->Controls->Add(this->pictureBox66);
			this->panel17->Controls->Add(this->pictureBox67);
			this->panel17->Controls->Add(this->pictureBox68);
			this->panel17->Controls->Add(this->pictureBox69);
			this->panel17->Controls->Add(this->pictureBox70);
			this->panel17->Controls->Add(this->pictureBox71);
			this->panel17->Controls->Add(this->pictureBox72);
			this->panel17->Controls->Add(this->pictureBox73);
			this->panel17->Controls->Add(this->pictureBox74);
			this->panel17->Controls->Add(this->pictureBox75);
			this->panel17->Controls->Add(this->pictureBox76);
			this->panel17->Controls->Add(this->pictureBox77);
			this->panel17->Controls->Add(this->pictureBox78);
			this->panel17->Controls->Add(this->pictureBox79);
			this->panel17->Controls->Add(this->pictureBox80);
			this->panel17->Controls->Add(this->pictureBox81);
			this->panel17->Controls->Add(this->pictureBox82);
			this->panel17->Controls->Add(this->pictureBox83);
			this->panel17->Controls->Add(this->pictureBox84);
			this->panel17->Controls->Add(this->pictureBox85);
			this->panel17->Controls->Add(this->pictureBox86);
			this->panel17->Controls->Add(this->pictureBox87);
			this->panel17->ForeColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->panel17->Location = System::Drawing::Point(767, 9);
			this->panel17->Name = L"panel17";
			this->panel17->Size = System::Drawing::Size(225, 192);
			this->panel17->TabIndex = 19;
			// 
			// button23
			// 
			this->button23->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(187)), static_cast<System::Int32>(static_cast<System::Byte>(221)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->button23->CausesValidation = false;
			this->button23->Font = (gcnew System::Drawing::Font(L"Courier New", 10, System::Drawing::FontStyle::Bold));
			this->button23->ForeColor = System::Drawing::Color::Black;
			this->button23->Location = System::Drawing::Point(157, 120);
			this->button23->Name = L"button23";
			this->button23->Size = System::Drawing::Size(56, 34);
			this->button23->TabIndex = 41;
			this->button23->Text = L"¬˚ıÓ‰";
			this->button23->UseVisualStyleBackColor = false;
			// 
			// button24
			// 
			this->button24->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(187)), static_cast<System::Int32>(static_cast<System::Byte>(221)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->button24->CausesValidation = false;
			this->button24->Font = (gcnew System::Drawing::Font(L"Courier New", 11, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->button24->ForeColor = System::Drawing::Color::Black;
			this->button24->Location = System::Drawing::Point(96, 120);
			this->button24->Name = L"button24";
			this->button24->Size = System::Drawing::Size(55, 34);
			this->button24->TabIndex = 40;
			this->button24->Text = L"—ÚÓÔ";
			this->button24->UseVisualStyleBackColor = false;
			// 
			// pictureBox64
			// 
			this->pictureBox64->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox64.Image")));
			this->pictureBox64->Location = System::Drawing::Point(173, 10);
			this->pictureBox64->Name = L"pictureBox64";
			this->pictureBox64->Size = System::Drawing::Size(25, 44);
			this->pictureBox64->TabIndex = 39;
			this->pictureBox64->TabStop = false;
			this->pictureBox64->Visible = false;
			// 
			// button25
			// 
			this->button25->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(187)), static_cast<System::Int32>(static_cast<System::Byte>(221)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->button25->CausesValidation = false;
			this->button25->Font = (gcnew System::Drawing::Font(L"Courier New", 11, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->button25->ForeColor = System::Drawing::Color::Black;
			this->button25->Location = System::Drawing::Point(35, 120);
			this->button25->Name = L"button25";
			this->button25->Size = System::Drawing::Size(55, 34);
			this->button25->TabIndex = 9;
			this->button25->Text = L"œÛÒÍ";
			this->button25->UseVisualStyleBackColor = false;
			// 
			// pictureBox65
			// 
			this->pictureBox65->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox65.Image")));
			this->pictureBox65->Location = System::Drawing::Point(80, 10);
			this->pictureBox65->Name = L"pictureBox65";
			this->pictureBox65->Size = System::Drawing::Size(25, 44);
			this->pictureBox65->TabIndex = 38;
			this->pictureBox65->TabStop = false;
			// 
			// pictureBox66
			// 
			this->pictureBox66->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox66.Image")));
			this->pictureBox66->Location = System::Drawing::Point(173, 10);
			this->pictureBox66->Name = L"pictureBox66";
			this->pictureBox66->Size = System::Drawing::Size(25, 44);
			this->pictureBox66->TabIndex = 25;
			this->pictureBox66->TabStop = false;
			// 
			// pictureBox67
			// 
			this->pictureBox67->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox67.Image")));
			this->pictureBox67->Location = System::Drawing::Point(173, 10);
			this->pictureBox67->Name = L"pictureBox67";
			this->pictureBox67->Size = System::Drawing::Size(25, 44);
			this->pictureBox67->TabIndex = 37;
			this->pictureBox67->TabStop = false;
			// 
			// pictureBox68
			// 
			this->pictureBox68->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox68.Image")));
			this->pictureBox68->Location = System::Drawing::Point(80, 10);
			this->pictureBox68->Name = L"pictureBox68";
			this->pictureBox68->Size = System::Drawing::Size(25, 44);
			this->pictureBox68->TabIndex = 36;
			this->pictureBox68->TabStop = false;
			// 
			// pictureBox69
			// 
			this->pictureBox69->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox69.Image")));
			this->pictureBox69->Location = System::Drawing::Point(173, 10);
			this->pictureBox69->Name = L"pictureBox69";
			this->pictureBox69->Size = System::Drawing::Size(25, 44);
			this->pictureBox69->TabIndex = 35;
			this->pictureBox69->TabStop = false;
			// 
			// pictureBox70
			// 
			this->pictureBox70->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox70.Image")));
			this->pictureBox70->InitialImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox70.InitialImage")));
			this->pictureBox70->Location = System::Drawing::Point(173, 10);
			this->pictureBox70->Name = L"pictureBox70";
			this->pictureBox70->Size = System::Drawing::Size(25, 44);
			this->pictureBox70->TabIndex = 34;
			this->pictureBox70->TabStop = false;
			// 
			// pictureBox71
			// 
			this->pictureBox71->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox71.Image")));
			this->pictureBox71->Location = System::Drawing::Point(142, 10);
			this->pictureBox71->Name = L"pictureBox71";
			this->pictureBox71->Size = System::Drawing::Size(25, 44);
			this->pictureBox71->TabIndex = 33;
			this->pictureBox71->TabStop = false;
			// 
			// pictureBox72
			// 
			this->pictureBox72->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox72.Image")));
			this->pictureBox72->Location = System::Drawing::Point(142, 10);
			this->pictureBox72->Name = L"pictureBox72";
			this->pictureBox72->Size = System::Drawing::Size(25, 44);
			this->pictureBox72->TabIndex = 32;
			this->pictureBox72->TabStop = false;
			// 
			// pictureBox73
			// 
			this->pictureBox73->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox73.Image")));
			this->pictureBox73->Location = System::Drawing::Point(142, 10);
			this->pictureBox73->Name = L"pictureBox73";
			this->pictureBox73->Size = System::Drawing::Size(25, 44);
			this->pictureBox73->TabIndex = 31;
			this->pictureBox73->TabStop = false;
			// 
			// pictureBox74
			// 
			this->pictureBox74->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox74.Image")));
			this->pictureBox74->Location = System::Drawing::Point(142, 10);
			this->pictureBox74->Name = L"pictureBox74";
			this->pictureBox74->Size = System::Drawing::Size(25, 44);
			this->pictureBox74->TabIndex = 30;
			this->pictureBox74->TabStop = false;
			// 
			// pictureBox75
			// 
			this->pictureBox75->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox75.Image")));
			this->pictureBox75->InitialImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox75.InitialImage")));
			this->pictureBox75->Location = System::Drawing::Point(142, 10);
			this->pictureBox75->Name = L"pictureBox75";
			this->pictureBox75->Size = System::Drawing::Size(25, 44);
			this->pictureBox75->TabIndex = 29;
			this->pictureBox75->TabStop = false;
			// 
			// pictureBox76
			// 
			this->pictureBox76->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox76.Image")));
			this->pictureBox76->Location = System::Drawing::Point(142, 10);
			this->pictureBox76->Name = L"pictureBox76";
			this->pictureBox76->Size = System::Drawing::Size(25, 44);
			this->pictureBox76->TabIndex = 28;
			this->pictureBox76->TabStop = false;
			// 
			// pictureBox77
			// 
			this->pictureBox77->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox77.Image")));
			this->pictureBox77->Location = System::Drawing::Point(173, 10);
			this->pictureBox77->Name = L"pictureBox77";
			this->pictureBox77->Size = System::Drawing::Size(25, 44);
			this->pictureBox77->TabIndex = 27;
			this->pictureBox77->TabStop = false;
			// 
			// pictureBox78
			// 
			this->pictureBox78->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox78.Image")));
			this->pictureBox78->Location = System::Drawing::Point(173, 10);
			this->pictureBox78->Name = L"pictureBox78";
			this->pictureBox78->Size = System::Drawing::Size(25, 44);
			this->pictureBox78->TabIndex = 26;
			this->pictureBox78->TabStop = false;
			// 
			// pictureBox79
			// 
			this->pictureBox79->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox79.Image")));
			this->pictureBox79->Location = System::Drawing::Point(173, 10);
			this->pictureBox79->Name = L"pictureBox79";
			this->pictureBox79->Size = System::Drawing::Size(25, 44);
			this->pictureBox79->TabIndex = 25;
			this->pictureBox79->TabStop = false;
			// 
			// pictureBox80
			// 
			this->pictureBox80->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox80.Image")));
			this->pictureBox80->Location = System::Drawing::Point(80, 10);
			this->pictureBox80->Name = L"pictureBox80";
			this->pictureBox80->Size = System::Drawing::Size(25, 44);
			this->pictureBox80->TabIndex = 24;
			this->pictureBox80->TabStop = false;
			// 
			// pictureBox81
			// 
			this->pictureBox81->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox81.Image")));
			this->pictureBox81->Location = System::Drawing::Point(80, 10);
			this->pictureBox81->Name = L"pictureBox81";
			this->pictureBox81->Size = System::Drawing::Size(25, 44);
			this->pictureBox81->TabIndex = 23;
			this->pictureBox81->TabStop = false;
			// 
			// pictureBox82
			// 
			this->pictureBox82->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox82.Image")));
			this->pictureBox82->Location = System::Drawing::Point(173, 10);
			this->pictureBox82->Name = L"pictureBox82";
			this->pictureBox82->Size = System::Drawing::Size(25, 44);
			this->pictureBox82->TabIndex = 22;
			this->pictureBox82->TabStop = false;
			// 
			// pictureBox83
			// 
			this->pictureBox83->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox83.Image")));
			this->pictureBox83->Location = System::Drawing::Point(80, 10);
			this->pictureBox83->Name = L"pictureBox83";
			this->pictureBox83->Size = System::Drawing::Size(25, 44);
			this->pictureBox83->TabIndex = 21;
			this->pictureBox83->TabStop = false;
			// 
			// pictureBox84
			// 
			this->pictureBox84->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox84.Image")));
			this->pictureBox84->Location = System::Drawing::Point(173, 10);
			this->pictureBox84->Name = L"pictureBox84";
			this->pictureBox84->Size = System::Drawing::Size(25, 44);
			this->pictureBox84->TabIndex = 20;
			this->pictureBox84->TabStop = false;
			// 
			// pictureBox85
			// 
			this->pictureBox85->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox85.Image")));
			this->pictureBox85->InitialImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox85.InitialImage")));
			this->pictureBox85->Location = System::Drawing::Point(49, 10);
			this->pictureBox85->Name = L"pictureBox85";
			this->pictureBox85->Size = System::Drawing::Size(25, 44);
			this->pictureBox85->TabIndex = 19;
			this->pictureBox85->TabStop = false;
			// 
			// pictureBox86
			// 
			this->pictureBox86->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox86.Image")));
			this->pictureBox86->Location = System::Drawing::Point(80, 10);
			this->pictureBox86->Name = L"pictureBox86";
			this->pictureBox86->Size = System::Drawing::Size(25, 44);
			this->pictureBox86->TabIndex = 19;
			this->pictureBox86->TabStop = false;
			// 
			// pictureBox87
			// 
			this->pictureBox87->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox87.Image")));
			this->pictureBox87->Location = System::Drawing::Point(111, 10);
			this->pictureBox87->Name = L"pictureBox87";
			this->pictureBox87->Size = System::Drawing::Size(25, 44);
			this->pictureBox87->TabIndex = 19;
			this->pictureBox87->TabStop = false;
			// 
			// panel18
			// 
			this->panel18->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(223)), 
				static_cast<System::Int32>(static_cast<System::Byte>(239)));
			this->panel18->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel18->Controls->Add(this->pictureBox88);
			this->panel18->Controls->Add(this->button26);
			this->panel18->Controls->Add(this->label16);
			this->panel18->ForeColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->panel18->Location = System::Drawing::Point(8, 9);
			this->panel18->Name = L"panel18";
			this->panel18->Size = System::Drawing::Size(282, 109);
			this->panel18->TabIndex = 6;
			// 
			// pictureBox88
			// 
			this->pictureBox88->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox88.Image")));
			this->pictureBox88->Location = System::Drawing::Point(8, 8);
			this->pictureBox88->Name = L"pictureBox88";
			this->pictureBox88->Size = System::Drawing::Size(127, 94);
			this->pictureBox88->TabIndex = 6;
			this->pictureBox88->TabStop = false;
			// 
			// button26
			// 
			this->button26->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(187)), static_cast<System::Int32>(static_cast<System::Byte>(221)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->button26->CausesValidation = false;
			this->button26->Font = (gcnew System::Drawing::Font(L"Courier New", 11, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->button26->ForeColor = System::Drawing::Color::Black;
			this->button26->Location = System::Drawing::Point(141, 57);
			this->button26->Name = L"button26";
			this->button26->Size = System::Drawing::Size(127, 28);
			this->button26->TabIndex = 9;
			this->button26->Text = L" ÛÔËÚ¸ ·ËÎÂÚ";
			this->button26->UseVisualStyleBackColor = false;
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label16->Font = (gcnew System::Drawing::Font(L"Courier New", 18, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)), 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->label16->ForeColor = System::Drawing::Color::Black;
			this->label16->Location = System::Drawing::Point(141, 8);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(126, 30);
			this->label16->TabIndex = 16;
			this->label16->Text = L" ÓÏ‡Ó‚Ó";
			// 
			// panel19
			// 
			this->panel19->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(223)), 
				static_cast<System::Int32>(static_cast<System::Byte>(239)));
			this->panel19->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel19->Controls->Add(this->pictureBox89);
			this->panel19->Controls->Add(this->button27);
			this->panel19->Controls->Add(this->label17);
			this->panel19->ForeColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->panel19->Location = System::Drawing::Point(8, 505);
			this->panel19->Name = L"panel19";
			this->panel19->Size = System::Drawing::Size(282, 109);
			this->panel19->TabIndex = 23;
			// 
			// pictureBox89
			// 
			this->pictureBox89->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox89.Image")));
			this->pictureBox89->Location = System::Drawing::Point(8, 8);
			this->pictureBox89->Name = L"pictureBox89";
			this->pictureBox89->Size = System::Drawing::Size(127, 94);
			this->pictureBox89->TabIndex = 6;
			this->pictureBox89->TabStop = false;
			// 
			// button27
			// 
			this->button27->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(187)), static_cast<System::Int32>(static_cast<System::Byte>(221)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->button27->CausesValidation = false;
			this->button27->Font = (gcnew System::Drawing::Font(L"Courier New", 11, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->button27->ForeColor = System::Drawing::Color::Black;
			this->button27->Location = System::Drawing::Point(141, 57);
			this->button27->Name = L"button27";
			this->button27->Size = System::Drawing::Size(127, 28);
			this->button27->TabIndex = 9;
			this->button27->Text = L" ÛÔËÚ¸ ·ËÎÂÚ";
			this->button27->UseVisualStyleBackColor = false;
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label17->Font = (gcnew System::Drawing::Font(L"Courier New", 18, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)), 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->label17->ForeColor = System::Drawing::Color::Black;
			this->label17->Location = System::Drawing::Point(141, 8);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(112, 30);
			this->label17->TabIndex = 16;
			this->label17->Text = L"¡‡Ì‡ÛÎ";
			// 
			// panel20
			// 
			this->panel20->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(223)), 
				static_cast<System::Int32>(static_cast<System::Byte>(239)));
			this->panel20->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel20->Controls->Add(this->pictureBox90);
			this->panel20->Controls->Add(this->button28);
			this->panel20->Controls->Add(this->label18);
			this->panel20->ForeColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->panel20->Location = System::Drawing::Point(470, 9);
			this->panel20->Name = L"panel20";
			this->panel20->Size = System::Drawing::Size(282, 109);
			this->panel20->TabIndex = 21;
			// 
			// pictureBox90
			// 
			this->pictureBox90->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox90.Image")));
			this->pictureBox90->Location = System::Drawing::Point(144, 8);
			this->pictureBox90->Name = L"pictureBox90";
			this->pictureBox90->Size = System::Drawing::Size(127, 94);
			this->pictureBox90->TabIndex = 6;
			this->pictureBox90->TabStop = false;
			// 
			// button28
			// 
			this->button28->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(187)), static_cast<System::Int32>(static_cast<System::Byte>(221)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->button28->CausesValidation = false;
			this->button28->Font = (gcnew System::Drawing::Font(L"Courier New", 11, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->button28->ForeColor = System::Drawing::Color::Black;
			this->button28->Location = System::Drawing::Point(8, 57);
			this->button28->Name = L"button28";
			this->button28->Size = System::Drawing::Size(127, 28);
			this->button28->TabIndex = 9;
			this->button28->Text = L" ÛÔËÚ¸ ·ËÎÂÚ";
			this->button28->UseVisualStyleBackColor = false;
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label18->Font = (gcnew System::Drawing::Font(L"Courier New", 18, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)), 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->label18->ForeColor = System::Drawing::Color::Black;
			this->label18->Location = System::Drawing::Point(22, 8);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(98, 30);
			this->label18->TabIndex = 16;
			this->label18->Text = L"«ËÏÌˇˇ";
			// 
			// Imitation
			// 
			this->Imitation->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(187)), static_cast<System::Int32>(static_cast<System::Byte>(221)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->Imitation->Controls->Add(this->pictureBox3);
			this->Imitation->Controls->Add(this->pictureBox4);
			this->Imitation->Controls->Add(this->pictureBox2);
			this->Imitation->Controls->Add(this->pictureBox1);
			this->Imitation->Controls->Add(this->panel2);
			this->Imitation->Controls->Add(this->panel22);
			this->Imitation->Controls->Add(this->panel23);
			this->Imitation->Controls->Add(this->panel24);
			this->Imitation->Controls->Add(this->panel25);
			this->Imitation->Controls->Add(this->panel21);
			this->Imitation->Controls->Add(this->hour4);
			this->Imitation->Location = System::Drawing::Point(4, 25);
			this->Imitation->Name = L"Imitation";
			this->Imitation->Padding = System::Windows::Forms::Padding(3);
			this->Imitation->Size = System::Drawing::Size(1008, 620);
			this->Imitation->TabIndex = 2;
			this->Imitation->Text = L"»ÏËÚ‡ˆËˇ ÔÓˆÂÒÒ‡ ‰‚ËÊÂÌËˇ";
			// 
			// pictureBox3
			// 
			this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox3.Image")));
			this->pictureBox3->Location = System::Drawing::Point(40, 440);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(319, 48);
			this->pictureBox3->TabIndex = 45;
			this->pictureBox3->TabStop = false;
			// 
			// pictureBox4
			// 
			this->pictureBox4->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox4.Image")));
			this->pictureBox4->Location = System::Drawing::Point(440, 440);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(319, 48);
			this->pictureBox4->TabIndex = 45;
			this->pictureBox4->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(440, 140);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(319, 48);
			this->pictureBox2->TabIndex = 45;
			this->pictureBox2->TabStop = false;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(40, 140);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(319, 48);
			this->pictureBox1->TabIndex = 45;
			this->pictureBox1->TabStop = false;
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::Silver;
			this->panel2->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel2->Controls->Add(this->label9);
			this->panel2->Controls->Add(this->st);
			this->panel2->Controls->Add(this->label7);
			this->panel2->Controls->Add(this->button30);
			this->panel2->Controls->Add(this->checkBox4);
			this->panel2->Controls->Add(this->label30);
			this->panel2->Controls->Add(this->comboBox2);
			this->panel2->Controls->Add(this->label99);
			this->panel2->Controls->Add(this->label24);
			this->panel2->Controls->Add(this->checkBox1);
			this->panel2->Controls->Add(this->label1);
			this->panel2->Controls->Add(this->checkBox3);
			this->panel2->Controls->Add(this->surname);
			this->panel2->Controls->Add(this->checkBox2);
			this->panel2->Controls->Add(this->label2);
			this->panel2->Controls->Add(this->label25);
			this->panel2->Controls->Add(this->label26);
			this->panel2->Controls->Add(this->comboBox4);
			this->panel2->Enabled = false;
			this->panel2->ForeColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->panel2->Location = System::Drawing::Point(775, 128);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(224, 480);
			this->panel2->TabIndex = 42;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Courier New", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label9->ForeColor = System::Drawing::SystemColors::HighlightText;
			this->label9->Location = System::Drawing::Point(10, 260);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(197, 17);
			this->label9->TabIndex = 1;
			this->label9->Text = L"“–≈¡Œ¬¿Õ»ﬂ œ¿——¿∆»–¿:";
			// 
			// st
			// 
			this->st->AutoSize = true;
			this->st->Font = (gcnew System::Drawing::Font(L"Courier New", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->st->ForeColor = System::Drawing::Color::Black;
			this->st->Location = System::Drawing::Point(10, 169);
			this->st->Name = L"st";
			this->st->Size = System::Drawing::Size(0, 16);
			this->st->TabIndex = 10;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->ForeColor = System::Drawing::SystemColors::HighlightText;
			this->label7->Location = System::Drawing::Point(9, 295);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(85, 16);
			this->label7->TabIndex = 1;
			this->label7->Text = L"“ËÔ ‚‡„ÓÌ‡:";
			// 
			// button30
			// 
			this->button30->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(187)), static_cast<System::Int32>(static_cast<System::Byte>(221)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->button30->CausesValidation = false;
			this->button30->Font = (gcnew System::Drawing::Font(L"Courier New", 11, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->button30->ForeColor = System::Drawing::Color::Black;
			this->button30->Location = System::Drawing::Point(164, 428);
			this->button30->Name = L"button30";
			this->button30->Size = System::Drawing::Size(43, 28);
			this->button30->TabIndex = 9;
			this->button30->Text = L"Ok";
			this->button30->UseVisualStyleBackColor = false;
			this->button30->Click += gcnew System::EventHandler(this, &Form1::button30_Click);
			// 
			// checkBox4
			// 
			this->checkBox4->AutoSize = true;
			this->checkBox4->Enabled = false;
			this->checkBox4->Font = (gcnew System::Drawing::Font(L"Courier New", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->checkBox4->ForeColor = System::Drawing::SystemColors::HighlightText;
			this->checkBox4->Location = System::Drawing::Point(11, 404);
			this->checkBox4->Name = L"checkBox4";
			this->checkBox4->Size = System::Drawing::Size(163, 20);
			this->checkBox4->TabIndex = 5;
			this->checkBox4->Text = L"“ÂÎÂÙÓÌ (+50 Û·)";
			this->checkBox4->UseVisualStyleBackColor = true;
			// 
			// label30
			// 
			this->label30->AutoSize = true;
			this->label30->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label30->Font = (gcnew System::Drawing::Font(L"Courier New", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label30->ForeColor = System::Drawing::Color::Red;
			this->label30->Location = System::Drawing::Point(134, 169);
			this->label30->Name = L"label30";
			this->label30->Size = System::Drawing::Size(28, 19);
			this->label30->TabIndex = 16;
			this->label30->Text = L"  ";
			// 
			// comboBox2
			// 
			this->comboBox2->Font = (gcnew System::Drawing::Font(L"Courier New", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L" ÛÔÂ", L"œÎ‡ˆÍ‡Ú", L"—Ë‰ˇ˜ËÈ"});
			this->comboBox2->Location = System::Drawing::Point(111, 292);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(89, 24);
			this->comboBox2->TabIndex = 0;
			this->comboBox2->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::comboBox2_SelectedIndexChanged);
			// 
			// label99
			// 
			this->label99->AutoSize = true;
			this->label99->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label99->Font = (gcnew System::Drawing::Font(L"Courier New", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label99->ForeColor = System::Drawing::Color::Red;
			this->label99->Location = System::Drawing::Point(13, 131);
			this->label99->Name = L"label99";
			this->label99->Size = System::Drawing::Size(55, 19);
			this->label99->TabIndex = 16;
			this->label99->Text = L"     ";
			// 
			// label24
			// 
			this->label24->AutoSize = true;
			this->label24->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label24->Font = (gcnew System::Drawing::Font(L"Courier New", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label24->ForeColor = System::Drawing::Color::Red;
			this->label24->Location = System::Drawing::Point(134, 209);
			this->label24->Name = L"label24";
			this->label24->Size = System::Drawing::Size(55, 19);
			this->label24->TabIndex = 16;
			this->label24->Text = L"     ";
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Font = (gcnew System::Drawing::Font(L"Courier New", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->checkBox1->ForeColor = System::Drawing::SystemColors::HighlightText;
			this->checkBox1->Location = System::Drawing::Point(11, 326);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(139, 20);
			this->checkBox1->TabIndex = 5;
			this->checkBox1->Text = L"¬‡„ÓÌ-ÂÒÚÓ‡Ì";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->ForeColor = System::Drawing::SystemColors::HighlightText;
			this->label1->Location = System::Drawing::Point(10, 59);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(132, 16);
			this->label1->TabIndex = 1;
			this->label1->Text = L"œÛÌÍÚ Ì‡ÁÌ‡˜ÂÌËˇ:";
			// 
			// checkBox3
			// 
			this->checkBox3->AutoSize = true;
			this->checkBox3->Enabled = false;
			this->checkBox3->Font = (gcnew System::Drawing::Font(L"Courier New", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->checkBox3->ForeColor = System::Drawing::SystemColors::HighlightText;
			this->checkBox3->Location = System::Drawing::Point(11, 378);
			this->checkBox3->Name = L"checkBox3";
			this->checkBox3->Size = System::Drawing::Size(187, 20);
			this->checkBox3->TabIndex = 5;
			this->checkBox3->Text = L"“ÂÎÂ‚ËÁÓ (+100 Û·)";
			this->checkBox3->UseVisualStyleBackColor = true;
			// 
			// surname
			// 
			this->surname->Font = (gcnew System::Drawing::Font(L"Courier New", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->surname->Location = System::Drawing::Point(87, 18);
			this->surname->Name = L"surname";
			this->surname->Size = System::Drawing::Size(109, 22);
			this->surname->TabIndex = 2;
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->Enabled = false;
			this->checkBox2->Font = (gcnew System::Drawing::Font(L"Courier New", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->checkBox2->ForeColor = System::Drawing::SystemColors::HighlightText;
			this->checkBox2->Location = System::Drawing::Point(11, 352);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(163, 20);
			this->checkBox2->TabIndex = 5;
			this->checkBox2->Text = L"œÓÒÚÂÎ¸ (+20 Û·)";
			this->checkBox2->UseVisualStyleBackColor = true;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->ForeColor = System::Drawing::SystemColors::HighlightText;
			this->label2->Location = System::Drawing::Point(10, 169);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(105, 16);
			this->label2->TabIndex = 1;
			this->label2->Text = L"ÕÓÏÂ ÔÓÂÁ‰‡:";
			// 
			// label25
			// 
			this->label25->AutoSize = true;
			this->label25->ForeColor = System::Drawing::SystemColors::HighlightText;
			this->label25->Location = System::Drawing::Point(10, 209);
			this->label25->Name = L"label25";
			this->label25->Size = System::Drawing::Size(112, 16);
			this->label25->TabIndex = 1;
			this->label25->Text = L"¬ÂÏˇ ÓÚ˙ÂÁ‰‡:";
			// 
			// label26
			// 
			this->label26->AutoSize = true;
			this->label26->ForeColor = System::Drawing::SystemColors::HighlightText;
			this->label26->Location = System::Drawing::Point(9, 21);
			this->label26->Name = L"label26";
			this->label26->Size = System::Drawing::Size(73, 16);
			this->label26->TabIndex = 1;
			this->label26->Text = L"‘‡ÏËÎËˇ:";
			// 
			// comboBox4
			// 
			this->comboBox4->Font = (gcnew System::Drawing::Font(L"Courier New", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->comboBox4->FormattingEnabled = true;
			this->comboBox4->Items->AddRange(gcnew cli::array< System::Object^  >(4) {L" ÓÏ‡Ó‚Ó", L"«ËÏÌˇˇ", L"¡‡Ì‡ÛÎ", L"¬‡Î¸ÍÓ‚Ó"});
			this->comboBox4->Location = System::Drawing::Point(12, 86);
			this->comboBox4->Name = L"comboBox4";
			this->comboBox4->Size = System::Drawing::Size(138, 24);
			this->comboBox4->TabIndex = 0;
			this->comboBox4->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::comboBox4_SelectedIndexChanged);
			// 
			// panel22
			// 
			this->panel22->BackColor = System::Drawing::Color::DimGray;
			this->panel22->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel22->Controls->Add(this->pictureBox92);
			this->panel22->Controls->Add(this->buttonval);
			this->panel22->Controls->Add(this->label20);
			this->panel22->ForeColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->panel22->Location = System::Drawing::Point(477, 499);
			this->panel22->Name = L"panel22";
			this->panel22->Size = System::Drawing::Size(282, 109);
			this->panel22->TabIndex = 26;
			// 
			// pictureBox92
			// 
			this->pictureBox92->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox92.Image")));
			this->pictureBox92->Location = System::Drawing::Point(144, 8);
			this->pictureBox92->Name = L"pictureBox92";
			this->pictureBox92->Size = System::Drawing::Size(127, 94);
			this->pictureBox92->TabIndex = 6;
			this->pictureBox92->TabStop = false;
			// 
			// buttonval
			// 
			this->buttonval->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(187)), static_cast<System::Int32>(static_cast<System::Byte>(221)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->buttonval->CausesValidation = false;
			this->buttonval->Font = (gcnew System::Drawing::Font(L"Courier New", 11, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->buttonval->ForeColor = System::Drawing::Color::Black;
			this->buttonval->Location = System::Drawing::Point(8, 57);
			this->buttonval->Name = L"buttonval";
			this->buttonval->Size = System::Drawing::Size(127, 28);
			this->buttonval->TabIndex = 9;
			this->buttonval->Text = L" ÛÔËÚ¸ ·ËÎÂÚ";
			this->buttonval->UseVisualStyleBackColor = false;
			this->buttonval->Click += gcnew System::EventHandler(this, &Form1::buttonval_Click);
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label20->Font = (gcnew System::Drawing::Font(L"Courier New", 18, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)), 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->label20->ForeColor = System::Drawing::Color::Black;
			this->label20->Location = System::Drawing::Point(9, 8);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(126, 30);
			this->label20->TabIndex = 16;
			this->label20->Text = L"¬‡Î¸ÍÓ‚Ó";
			// 
			// panel23
			// 
			this->panel23->BackColor = System::Drawing::Color::LightGray;
			this->panel23->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel23->Controls->Add(this->button31);
			this->panel23->Controls->Add(this->button32);
			this->panel23->Controls->Add(this->ten1);
			this->panel23->Controls->Add(this->sec0);
			this->panel23->Controls->Add(this->ten_hour);
			this->panel23->Controls->Add(this->hour2);
			this->panel23->ForeColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->panel23->Location = System::Drawing::Point(775, 8);
			this->panel23->Name = L"panel23";
			this->panel23->Size = System::Drawing::Size(225, 109);
			this->panel23->TabIndex = 24;
			// 
			// button31
			// 
			this->button31->BackColor = System::Drawing::Color::Red;
			this->button31->CausesValidation = false;
			this->button31->Font = (gcnew System::Drawing::Font(L"Courier New", 10, System::Drawing::FontStyle::Bold));
			this->button31->ForeColor = System::Drawing::Color::Black;
			this->button31->Location = System::Drawing::Point(132, 60);
			this->button31->Name = L"button31";
			this->button31->Size = System::Drawing::Size(56, 34);
			this->button31->TabIndex = 41;
			this->button31->Text = L"¬˚ıÓ‰";
			this->button31->UseVisualStyleBackColor = false;
			this->button31->Click += gcnew System::EventHandler(this, &Form1::button31_Click);
			// 
			// button32
			// 
			this->button32->BackColor = System::Drawing::Color::Lime;
			this->button32->CausesValidation = false;
			this->button32->Font = (gcnew System::Drawing::Font(L"Courier New", 11, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->button32->ForeColor = System::Drawing::Color::Black;
			this->button32->Location = System::Drawing::Point(39, 60);
			this->button32->Name = L"button32";
			this->button32->Size = System::Drawing::Size(87, 34);
			this->button32->TabIndex = 40;
			this->button32->Text = L"œ”— ";
			this->button32->UseVisualStyleBackColor = false;
			this->button32->Click += gcnew System::EventHandler(this, &Form1::button32_Click);
			// 
			// ten1
			// 
			this->ten1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"ten1.Image")));
			this->ten1->InitialImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"ten1.InitialImage")));
			this->ten1->Location = System::Drawing::Point(132, 10);
			this->ten1->Name = L"ten1";
			this->ten1->Size = System::Drawing::Size(25, 44);
			this->ten1->TabIndex = 29;
			this->ten1->TabStop = false;
			// 
			// sec0
			// 
			this->sec0->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"sec0.Image")));
			this->sec0->Location = System::Drawing::Point(163, 10);
			this->sec0->Name = L"sec0";
			this->sec0->Size = System::Drawing::Size(25, 44);
			this->sec0->TabIndex = 27;
			this->sec0->TabStop = false;
			// 
			// ten_hour
			// 
			this->ten_hour->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"ten_hour.Image")));
			this->ten_hour->InitialImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"ten_hour.InitialImage")));
			this->ten_hour->Location = System::Drawing::Point(39, 10);
			this->ten_hour->Name = L"ten_hour";
			this->ten_hour->Size = System::Drawing::Size(25, 44);
			this->ten_hour->TabIndex = 19;
			this->ten_hour->TabStop = false;
			// 
			// hour2
			// 
			this->hour2->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"hour2.Image")));
			this->hour2->Location = System::Drawing::Point(70, 10);
			this->hour2->Name = L"hour2";
			this->hour2->Size = System::Drawing::Size(25, 44);
			this->hour2->TabIndex = 19;
			this->hour2->TabStop = false;
			// 
			// panel24
			// 
			this->panel24->BackColor = System::Drawing::Color::DimGray;
			this->panel24->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel24->Controls->Add(this->pictureBox117);
			this->panel24->Controls->Add(this->buttonbar);
			this->panel24->Controls->Add(this->label21);
			this->panel24->ForeColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->panel24->Location = System::Drawing::Point(13, 499);
			this->panel24->Name = L"panel24";
			this->panel24->Size = System::Drawing::Size(282, 109);
			this->panel24->TabIndex = 27;
			// 
			// pictureBox117
			// 
			this->pictureBox117->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox117.Image")));
			this->pictureBox117->Location = System::Drawing::Point(8, 8);
			this->pictureBox117->Name = L"pictureBox117";
			this->pictureBox117->Size = System::Drawing::Size(127, 94);
			this->pictureBox117->TabIndex = 6;
			this->pictureBox117->TabStop = false;
			// 
			// buttonbar
			// 
			this->buttonbar->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(187)), static_cast<System::Int32>(static_cast<System::Byte>(221)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->buttonbar->CausesValidation = false;
			this->buttonbar->Font = (gcnew System::Drawing::Font(L"Courier New", 11, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->buttonbar->ForeColor = System::Drawing::Color::Black;
			this->buttonbar->Location = System::Drawing::Point(141, 57);
			this->buttonbar->Name = L"buttonbar";
			this->buttonbar->Size = System::Drawing::Size(127, 28);
			this->buttonbar->TabIndex = 9;
			this->buttonbar->Text = L" ÛÔËÚ¸ ·ËÎÂÚ";
			this->buttonbar->UseVisualStyleBackColor = false;
			this->buttonbar->Click += gcnew System::EventHandler(this, &Form1::buttonbar_Click);
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label21->Font = (gcnew System::Drawing::Font(L"Courier New", 18, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)), 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->label21->ForeColor = System::Drawing::Color::Black;
			this->label21->Location = System::Drawing::Point(141, 8);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(112, 30);
			this->label21->TabIndex = 16;
			this->label21->Text = L"¡‡Ì‡ÛÎ";
			// 
			// panel25
			// 
			this->panel25->BackColor = System::Drawing::Color::DimGray;
			this->panel25->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel25->Controls->Add(this->pictureBox118);
			this->panel25->Controls->Add(this->buttonzim);
			this->panel25->Controls->Add(this->label22);
			this->panel25->ForeColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->panel25->Location = System::Drawing::Point(477, 8);
			this->panel25->Name = L"panel25";
			this->panel25->Size = System::Drawing::Size(282, 109);
			this->panel25->TabIndex = 25;
			// 
			// pictureBox118
			// 
			this->pictureBox118->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox118.Image")));
			this->pictureBox118->Location = System::Drawing::Point(144, 8);
			this->pictureBox118->Name = L"pictureBox118";
			this->pictureBox118->Size = System::Drawing::Size(127, 94);
			this->pictureBox118->TabIndex = 6;
			this->pictureBox118->TabStop = false;
			// 
			// buttonzim
			// 
			this->buttonzim->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(187)), static_cast<System::Int32>(static_cast<System::Byte>(221)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->buttonzim->CausesValidation = false;
			this->buttonzim->Font = (gcnew System::Drawing::Font(L"Courier New", 11, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->buttonzim->ForeColor = System::Drawing::Color::Black;
			this->buttonzim->Location = System::Drawing::Point(8, 57);
			this->buttonzim->Name = L"buttonzim";
			this->buttonzim->Size = System::Drawing::Size(127, 28);
			this->buttonzim->TabIndex = 9;
			this->buttonzim->Text = L" ÛÔËÚ¸ ·ËÎÂÚ";
			this->buttonzim->UseVisualStyleBackColor = false;
			this->buttonzim->Click += gcnew System::EventHandler(this, &Form1::buttonzim_Click);
			// 
			// label22
			// 
			this->label22->AutoSize = true;
			this->label22->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label22->Font = (gcnew System::Drawing::Font(L"Courier New", 18, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)), 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->label22->ForeColor = System::Drawing::Color::Black;
			this->label22->Location = System::Drawing::Point(22, 8);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(98, 30);
			this->label22->TabIndex = 16;
			this->label22->Text = L"«ËÏÌˇˇ";
			// 
			// panel21
			// 
			this->panel21->BackColor = System::Drawing::Color::DimGray;
			this->panel21->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel21->Controls->Add(this->pictureBox91);
			this->panel21->Controls->Add(this->buttoncom);
			this->panel21->Controls->Add(this->label19);
			this->panel21->ForeColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->panel21->Location = System::Drawing::Point(13, 6);
			this->panel21->Name = L"panel21";
			this->panel21->Size = System::Drawing::Size(282, 109);
			this->panel21->TabIndex = 7;
			// 
			// pictureBox91
			// 
			this->pictureBox91->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox91.Image")));
			this->pictureBox91->Location = System::Drawing::Point(8, 8);
			this->pictureBox91->Name = L"pictureBox91";
			this->pictureBox91->Size = System::Drawing::Size(127, 94);
			this->pictureBox91->TabIndex = 6;
			this->pictureBox91->TabStop = false;
			// 
			// buttoncom
			// 
			this->buttoncom->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(187)), static_cast<System::Int32>(static_cast<System::Byte>(221)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->buttoncom->CausesValidation = false;
			this->buttoncom->Font = (gcnew System::Drawing::Font(L"Courier New", 11, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->buttoncom->ForeColor = System::Drawing::Color::Black;
			this->buttoncom->Location = System::Drawing::Point(141, 57);
			this->buttoncom->Name = L"buttoncom";
			this->buttoncom->Size = System::Drawing::Size(127, 28);
			this->buttoncom->TabIndex = 9;
			this->buttoncom->Text = L" ÛÔËÚ¸ ·ËÎÂÚ";
			this->buttoncom->UseVisualStyleBackColor = false;
			this->buttoncom->Click += gcnew System::EventHandler(this, &Form1::buttoncom_Click);
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label19->Font = (gcnew System::Drawing::Font(L"Courier New", 18, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)), 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->label19->ForeColor = System::Drawing::Color::Black;
			this->label19->Location = System::Drawing::Point(141, 8);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(126, 30);
			this->label19->TabIndex = 16;
			this->label19->Text = L" ÓÏ‡Ó‚Ó";
			// 
			// hour4
			// 
			this->hour4->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"hour4.Image")));
			this->hour4->Location = System::Drawing::Point(933, 8);
			this->hour4->Name = L"hour4";
			this->hour4->Size = System::Drawing::Size(25, 44);
			this->hour4->TabIndex = 21;
			this->hour4->TabStop = false;
			// 
			// tabImitation
			// 
			this->tabImitation->Controls->Add(this->Imitation);
			this->tabImitation->Controls->Add(this->tabPage8);
			this->tabImitation->Controls->Add(this->tabPage1);
			this->tabImitation->Controls->Add(this->tabPage6);
			this->tabImitation->Controls->Add(this->tabPage5);
			this->tabImitation->Controls->Add(this->tabPage7);
			this->tabImitation->Controls->Add(this->tabPage14);
			this->tabImitation->Font = (gcnew System::Drawing::Font(L"Courier New", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(206)));
			this->tabImitation->Location = System::Drawing::Point(0, 28);
			this->tabImitation->Name = L"tabImitation";
			this->tabImitation->SelectedIndex = 0;
			this->tabImitation->Size = System::Drawing::Size(1016, 649);
			this->tabImitation->TabIndex = 19;
			// 
			// tabPage8
			// 
			this->tabPage8->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(187)), static_cast<System::Int32>(static_cast<System::Byte>(221)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->tabPage8->Controls->Add(this->label31);
			this->tabPage8->Controls->Add(this->label32);
			this->tabPage8->Controls->Add(this->label29);
			this->tabPage8->Controls->Add(this->label28);
			this->tabPage8->Controls->Add(this->label27);
			this->tabPage8->Controls->Add(this->valnum3);
			this->tabPage8->Controls->Add(this->comnum3);
			this->tabPage8->Controls->Add(this->valnum1);
			this->tabPage8->Controls->Add(this->barnum3);
			this->tabPage8->Controls->Add(this->zimnum3);
			this->tabPage8->Controls->Add(this->zimnum1);
			this->tabPage8->Controls->Add(this->comnum2);
			this->tabPage8->Controls->Add(this->valnum2);
			this->tabPage8->Controls->Add(this->barnum1);
			this->tabPage8->Controls->Add(this->barnum2);
			this->tabPage8->Controls->Add(this->zimnum2);
			this->tabPage8->Controls->Add(this->comnum1);
			this->tabPage8->Controls->Add(this->label54);
			this->tabPage8->Controls->Add(this->zim2);
			this->tabPage8->Controls->Add(this->label59);
			this->tabPage8->Controls->Add(this->label45);
			this->tabPage8->Controls->Add(this->label53);
			this->tabPage8->Controls->Add(this->label83);
			this->tabPage8->Controls->Add(this->label112);
			this->tabPage8->Controls->Add(this->label108);
			this->tabPage8->Controls->Add(this->val3);
			this->tabPage8->Controls->Add(this->val2);
			this->tabPage8->Controls->Add(this->label52);
			this->tabPage8->Controls->Add(this->zim3);
			this->tabPage8->Controls->Add(this->label91);
			this->tabPage8->Controls->Add(this->bar3);
			this->tabPage8->Controls->Add(this->label73);
			this->tabPage8->Controls->Add(this->bar1);
			this->tabPage8->Controls->Add(this->com3);
			this->tabPage8->Controls->Add(this->com2);
			this->tabPage8->Controls->Add(this->zim1);
			this->tabPage8->Controls->Add(this->bar2);
			this->tabPage8->Controls->Add(this->label114);
			this->tabPage8->Controls->Add(this->val1);
			this->tabPage8->Controls->Add(this->label37);
			this->tabPage8->Controls->Add(this->com1);
			this->tabPage8->Controls->Add(this->label104);
			this->tabPage8->Controls->Add(this->label103);
			this->tabPage8->Controls->Add(this->label102);
			this->tabPage8->Controls->Add(this->barnaz1);
			this->tabPage8->Controls->Add(this->comnaz3);
			this->tabPage8->Controls->Add(this->valnaz3);
			this->tabPage8->Controls->Add(this->barnaz2);
			this->tabPage8->Controls->Add(this->valnaz1);
			this->tabPage8->Controls->Add(this->barnaz3);
			this->tabPage8->Controls->Add(this->label70);
			this->tabPage8->Controls->Add(this->label69);
			this->tabPage8->Controls->Add(this->label66);
			this->tabPage8->Controls->Add(this->comnaz1);
			this->tabPage8->Controls->Add(this->label58);
			this->tabPage8->Controls->Add(this->label39);
			this->tabPage8->Controls->Add(this->zimnaz1);
			this->tabPage8->Controls->Add(this->zimnaz3);
			this->tabPage8->Controls->Add(this->label33);
			this->tabPage8->Controls->Add(this->label86);
			this->tabPage8->Controls->Add(this->label85);
			this->tabPage8->Controls->Add(this->label84);
			this->tabPage8->Controls->Add(this->comnaz2);
			this->tabPage8->Controls->Add(this->valnaz2);
			this->tabPage8->Controls->Add(this->zimnaz2);
			this->tabPage8->ForeColor = System::Drawing::Color::Magenta;
			this->tabPage8->Location = System::Drawing::Point(4, 25);
			this->tabPage8->Name = L"tabPage8";
			this->tabPage8->Padding = System::Windows::Forms::Padding(3);
			this->tabPage8->Size = System::Drawing::Size(1008, 620);
			this->tabPage8->TabIndex = 8;
			this->tabPage8->Text = L"–‡ÒÔËÒ‡ÌËÂ";
			// 
			// label31
			// 
			this->label31->AutoSize = true;
			this->label31->Font = (gcnew System::Drawing::Font(L"Courier New", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label31->ForeColor = System::Drawing::Color::Red;
			this->label31->Location = System::Drawing::Point(603, 18);
			this->label31->Name = L"label31";
			this->label31->Size = System::Drawing::Size(116, 17);
			this->label31->TabIndex = 1;
			this->label31->Text = L"¬ÂÏˇ Û·˚ÚËˇ";
			// 
			// label32
			// 
			this->label32->AutoSize = true;
			this->label32->Font = (gcnew System::Drawing::Font(L"Courier New", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label32->ForeColor = System::Drawing::Color::Red;
			this->label32->Location = System::Drawing::Point(754, 18);
			this->label32->Name = L"label32";
			this->label32->Size = System::Drawing::Size(134, 17);
			this->label32->TabIndex = 1;
			this->label32->Text = L"¬ÂÏˇ ÔË·˚ÚËˇ";
			// 
			// label29
			// 
			this->label29->AutoSize = true;
			this->label29->Font = (gcnew System::Drawing::Font(L"Courier New", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label29->ForeColor = System::Drawing::Color::Red;
			this->label29->Location = System::Drawing::Point(223, 18);
			this->label29->Name = L"label29";
			this->label29->Size = System::Drawing::Size(161, 17);
			this->label29->TabIndex = 1;
			this->label29->Text = L"œÛÌÍÚ ÓÚÔ‡‚ÎÂÌËˇ";
			// 
			// label28
			// 
			this->label28->AutoSize = true;
			this->label28->Font = (gcnew System::Drawing::Font(L"Courier New", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label28->ForeColor = System::Drawing::Color::Red;
			this->label28->Location = System::Drawing::Point(414, 18);
			this->label28->Name = L"label28";
			this->label28->Size = System::Drawing::Size(152, 17);
			this->label28->TabIndex = 1;
			this->label28->Text = L"œÛÌÍÚ Ì‡ÁÌ‡˜ÂÌËˇ";
			// 
			// label27
			// 
			this->label27->AutoSize = true;
			this->label27->Font = (gcnew System::Drawing::Font(L"Courier New", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label27->ForeColor = System::Drawing::Color::Red;
			this->label27->Location = System::Drawing::Point(85, 18);
			this->label27->Name = L"label27";
			this->label27->Size = System::Drawing::Size(116, 17);
			this->label27->TabIndex = 1;
			this->label27->Text = L"ÕÓÏÂ ÔÓÂÁ‰‡";
			// 
			// valnum3
			// 
			this->valnum3->AutoSize = true;
			this->valnum3->ForeColor = System::Drawing::Color::Magenta;
			this->valnum3->Location = System::Drawing::Point(163, 446);
			this->valnum3->Name = L"valnum3";
			this->valnum3->Size = System::Drawing::Size(15, 16);
			this->valnum3->TabIndex = 0;
			this->valnum3->Text = L"1";
			// 
			// comnum3
			// 
			this->comnum3->AutoSize = true;
			this->comnum3->ForeColor = System::Drawing::Color::Green;
			this->comnum3->Location = System::Drawing::Point(163, 114);
			this->comnum3->Name = L"comnum3";
			this->comnum3->Size = System::Drawing::Size(15, 16);
			this->comnum3->TabIndex = 0;
			this->comnum3->Text = L"4";
			// 
			// valnum1
			// 
			this->valnum1->AutoSize = true;
			this->valnum1->ForeColor = System::Drawing::Color::Magenta;
			this->valnum1->Location = System::Drawing::Point(163, 386);
			this->valnum1->Name = L"valnum1";
			this->valnum1->Size = System::Drawing::Size(15, 16);
			this->valnum1->TabIndex = 0;
			this->valnum1->Text = L"4";
			// 
			// barnum3
			// 
			this->barnum3->AutoSize = true;
			this->barnum3->ForeColor = System::Drawing::Color::Navy;
			this->barnum3->Location = System::Drawing::Point(163, 331);
			this->barnum3->Name = L"barnum3";
			this->barnum3->Size = System::Drawing::Size(15, 16);
			this->barnum3->TabIndex = 0;
			this->barnum3->Text = L"4";
			// 
			// zimnum3
			// 
			this->zimnum3->AutoSize = true;
			this->zimnum3->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->zimnum3->Location = System::Drawing::Point(163, 221);
			this->zimnum3->Name = L"zimnum3";
			this->zimnum3->Size = System::Drawing::Size(15, 16);
			this->zimnum3->TabIndex = 0;
			this->zimnum3->Text = L"3";
			// 
			// zimnum1
			// 
			this->zimnum1->AutoSize = true;
			this->zimnum1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->zimnum1->Location = System::Drawing::Point(163, 161);
			this->zimnum1->Name = L"zimnum1";
			this->zimnum1->Size = System::Drawing::Size(15, 16);
			this->zimnum1->TabIndex = 0;
			this->zimnum1->Text = L"2";
			// 
			// comnum2
			// 
			this->comnum2->AutoSize = true;
			this->comnum2->ForeColor = System::Drawing::Color::Green;
			this->comnum2->Location = System::Drawing::Point(163, 84);
			this->comnum2->Name = L"comnum2";
			this->comnum2->Size = System::Drawing::Size(15, 16);
			this->comnum2->TabIndex = 0;
			this->comnum2->Text = L"3";
			// 
			// valnum2
			// 
			this->valnum2->AutoSize = true;
			this->valnum2->ForeColor = System::Drawing::Color::Magenta;
			this->valnum2->Location = System::Drawing::Point(163, 416);
			this->valnum2->Name = L"valnum2";
			this->valnum2->Size = System::Drawing::Size(15, 16);
			this->valnum2->TabIndex = 0;
			this->valnum2->Text = L"2";
			// 
			// barnum1
			// 
			this->barnum1->AutoSize = true;
			this->barnum1->ForeColor = System::Drawing::Color::Navy;
			this->barnum1->Location = System::Drawing::Point(163, 271);
			this->barnum1->Name = L"barnum1";
			this->barnum1->Size = System::Drawing::Size(15, 16);
			this->barnum1->TabIndex = 0;
			this->barnum1->Text = L"3";
			// 
			// barnum2
			// 
			this->barnum2->AutoSize = true;
			this->barnum2->ForeColor = System::Drawing::Color::Navy;
			this->barnum2->Location = System::Drawing::Point(163, 301);
			this->barnum2->Name = L"barnum2";
			this->barnum2->Size = System::Drawing::Size(15, 16);
			this->barnum2->TabIndex = 0;
			this->barnum2->Text = L"2";
			// 
			// zimnum2
			// 
			this->zimnum2->AutoSize = true;
			this->zimnum2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->zimnum2->Location = System::Drawing::Point(163, 191);
			this->zimnum2->Name = L"zimnum2";
			this->zimnum2->Size = System::Drawing::Size(15, 16);
			this->zimnum2->TabIndex = 0;
			this->zimnum2->Text = L"1";
			// 
			// comnum1
			// 
			this->comnum1->AutoSize = true;
			this->comnum1->ForeColor = System::Drawing::Color::Green;
			this->comnum1->Location = System::Drawing::Point(163, 54);
			this->comnum1->Name = L"comnum1";
			this->comnum1->Size = System::Drawing::Size(15, 16);
			this->comnum1->TabIndex = 0;
			this->comnum1->Text = L"1";
			// 
			// label54
			// 
			this->label54->AutoSize = true;
			this->label54->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->label54->Location = System::Drawing::Point(796, 161);
			this->label54->Name = L"label54";
			this->label54->Size = System::Drawing::Size(36, 16);
			this->label54->TabIndex = 0;
			this->label54->Text = L"**-20";
			// 
			// zim2
			// 
			this->zim2->AutoSize = true;
			this->zim2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->zim2->Location = System::Drawing::Point(632, 191);
			this->zim2->Name = L"zim2";
			this->zim2->Size = System::Drawing::Size(36, 16);
			this->zim2->TabIndex = 0;
			this->zim2->Text = L"**-30";
			// 
			// label59
			// 
			this->label59->AutoSize = true;
			this->label59->ForeColor = System::Drawing::Color::Green;
			this->label59->Location = System::Drawing::Point(796, 114);
			this->label59->Name = L"label59";
			this->label59->Size = System::Drawing::Size(36, 16);
			this->label59->TabIndex = 0;
			this->label59->Text = L"**-20";
			// 
			// label45
			// 
			this->label45->AutoSize = true;
			this->label45->ForeColor = System::Drawing::Color::Green;
			this->label45->Location = System::Drawing::Point(796, 84);
			this->label45->Name = L"label45";
			this->label45->Size = System::Drawing::Size(36, 16);
			this->label45->TabIndex = 0;
			this->label45->Text = L"**-20";
			// 
			// label53
			// 
			this->label53->AutoSize = true;
			this->label53->ForeColor = System::Drawing::Color::Navy;
			this->label53->Location = System::Drawing::Point(796, 271);
			this->label53->Name = L"label53";
			this->label53->Size = System::Drawing::Size(36, 16);
			this->label53->TabIndex = 0;
			this->label53->Text = L"**-20";
			// 
			// label83
			// 
			this->label83->AutoSize = true;
			this->label83->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->label83->Location = System::Drawing::Point(796, 221);
			this->label83->Name = L"label83";
			this->label83->Size = System::Drawing::Size(36, 16);
			this->label83->TabIndex = 0;
			this->label83->Text = L"**-50";
			// 
			// label112
			// 
			this->label112->AutoSize = true;
			this->label112->ForeColor = System::Drawing::Color::Magenta;
			this->label112->Location = System::Drawing::Point(796, 446);
			this->label112->Name = L"label112";
			this->label112->Size = System::Drawing::Size(36, 16);
			this->label112->TabIndex = 0;
			this->label112->Text = L"**-10";
			// 
			// label108
			// 
			this->label108->AutoSize = true;
			this->label108->ForeColor = System::Drawing::Color::Magenta;
			this->label108->Location = System::Drawing::Point(796, 416);
			this->label108->Name = L"label108";
			this->label108->Size = System::Drawing::Size(36, 16);
			this->label108->TabIndex = 0;
			this->label108->Text = L"**-50";
			// 
			// val3
			// 
			this->val3->AutoSize = true;
			this->val3->ForeColor = System::Drawing::Color::Magenta;
			this->val3->Location = System::Drawing::Point(632, 446);
			this->val3->Name = L"val3";
			this->val3->Size = System::Drawing::Size(36, 16);
			this->val3->TabIndex = 0;
			this->val3->Text = L"**-00";
			// 
			// val2
			// 
			this->val2->AutoSize = true;
			this->val2->ForeColor = System::Drawing::Color::Magenta;
			this->val2->Location = System::Drawing::Point(632, 416);
			this->val2->Name = L"val2";
			this->val2->Size = System::Drawing::Size(36, 16);
			this->val2->TabIndex = 0;
			this->val2->Text = L"**-00";
			// 
			// label52
			// 
			this->label52->AutoSize = true;
			this->label52->ForeColor = System::Drawing::Color::Navy;
			this->label52->Location = System::Drawing::Point(796, 301);
			this->label52->Name = L"label52";
			this->label52->Size = System::Drawing::Size(36, 16);
			this->label52->TabIndex = 0;
			this->label52->Text = L"**-50";
			// 
			// zim3
			// 
			this->zim3->AutoSize = true;
			this->zim3->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->zim3->Location = System::Drawing::Point(632, 221);
			this->zim3->Name = L"zim3";
			this->zim3->Size = System::Drawing::Size(36, 16);
			this->zim3->TabIndex = 0;
			this->zim3->Text = L"**-30";
			// 
			// label91
			// 
			this->label91->AutoSize = true;
			this->label91->ForeColor = System::Drawing::Color::Navy;
			this->label91->Location = System::Drawing::Point(796, 331);
			this->label91->Name = L"label91";
			this->label91->Size = System::Drawing::Size(36, 16);
			this->label91->TabIndex = 0;
			this->label91->Text = L"**-50";
			// 
			// bar3
			// 
			this->bar3->AutoSize = true;
			this->bar3->ForeColor = System::Drawing::Color::Navy;
			this->bar3->Location = System::Drawing::Point(632, 331);
			this->bar3->Name = L"bar3";
			this->bar3->Size = System::Drawing::Size(36, 16);
			this->bar3->TabIndex = 0;
			this->bar3->Text = L"**-30";
			// 
			// label73
			// 
			this->label73->AutoSize = true;
			this->label73->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->label73->Location = System::Drawing::Point(796, 191);
			this->label73->Name = L"label73";
			this->label73->Size = System::Drawing::Size(36, 16);
			this->label73->TabIndex = 0;
			this->label73->Text = L"**-50";
			// 
			// bar1
			// 
			this->bar1->AutoSize = true;
			this->bar1->ForeColor = System::Drawing::Color::Navy;
			this->bar1->Location = System::Drawing::Point(632, 271);
			this->bar1->Name = L"bar1";
			this->bar1->Size = System::Drawing::Size(36, 16);
			this->bar1->TabIndex = 0;
			this->bar1->Text = L"**-00";
			// 
			// com3
			// 
			this->com3->AutoSize = true;
			this->com3->ForeColor = System::Drawing::Color::Green;
			this->com3->Location = System::Drawing::Point(632, 114);
			this->com3->Name = L"com3";
			this->com3->Size = System::Drawing::Size(36, 16);
			this->com3->TabIndex = 0;
			this->com3->Text = L"**-00";
			// 
			// com2
			// 
			this->com2->AutoSize = true;
			this->com2->ForeColor = System::Drawing::Color::Green;
			this->com2->Location = System::Drawing::Point(632, 84);
			this->com2->Name = L"com2";
			this->com2->Size = System::Drawing::Size(36, 16);
			this->com2->TabIndex = 0;
			this->com2->Text = L"**-00";
			// 
			// zim1
			// 
			this->zim1->AutoSize = true;
			this->zim1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->zim1->Location = System::Drawing::Point(632, 161);
			this->zim1->Name = L"zim1";
			this->zim1->Size = System::Drawing::Size(36, 16);
			this->zim1->TabIndex = 0;
			this->zim1->Text = L"**-00";
			// 
			// bar2
			// 
			this->bar2->AutoSize = true;
			this->bar2->ForeColor = System::Drawing::Color::Navy;
			this->bar2->Location = System::Drawing::Point(632, 301);
			this->bar2->Name = L"bar2";
			this->bar2->Size = System::Drawing::Size(36, 16);
			this->bar2->TabIndex = 0;
			this->bar2->Text = L"**-30";
			// 
			// label114
			// 
			this->label114->AutoSize = true;
			this->label114->ForeColor = System::Drawing::Color::Magenta;
			this->label114->Location = System::Drawing::Point(796, 386);
			this->label114->Name = L"label114";
			this->label114->Size = System::Drawing::Size(36, 16);
			this->label114->TabIndex = 0;
			this->label114->Text = L"**-20";
			// 
			// val1
			// 
			this->val1->AutoSize = true;
			this->val1->ForeColor = System::Drawing::Color::Magenta;
			this->val1->Location = System::Drawing::Point(632, 386);
			this->val1->Name = L"val1";
			this->val1->Size = System::Drawing::Size(36, 16);
			this->val1->TabIndex = 0;
			this->val1->Text = L"**-00";
			// 
			// label37
			// 
			this->label37->AutoSize = true;
			this->label37->ForeColor = System::Drawing::Color::Green;
			this->label37->Location = System::Drawing::Point(796, 54);
			this->label37->Name = L"label37";
			this->label37->Size = System::Drawing::Size(36, 16);
			this->label37->TabIndex = 0;
			this->label37->Text = L"**-20";
			// 
			// com1
			// 
			this->com1->AutoSize = true;
			this->com1->ForeColor = System::Drawing::Color::Green;
			this->com1->Location = System::Drawing::Point(632, 54);
			this->com1->Name = L"com1";
			this->com1->Size = System::Drawing::Size(36, 16);
			this->com1->TabIndex = 0;
			this->com1->Text = L"**-00";
			// 
			// label104
			// 
			this->label104->AutoSize = true;
			this->label104->ForeColor = System::Drawing::Color::Magenta;
			this->label104->Location = System::Drawing::Point(267, 446);
			this->label104->Name = L"label104";
			this->label104->Size = System::Drawing::Size(72, 16);
			this->label104->TabIndex = 0;
			this->label104->Text = L"¬‡Î¸ÍÓ‚Ó";
			// 
			// label103
			// 
			this->label103->AutoSize = true;
			this->label103->ForeColor = System::Drawing::Color::Magenta;
			this->label103->Location = System::Drawing::Point(267, 416);
			this->label103->Name = L"label103";
			this->label103->Size = System::Drawing::Size(72, 16);
			this->label103->TabIndex = 0;
			this->label103->Text = L"¬‡Î¸ÍÓ‚Ó";
			// 
			// label102
			// 
			this->label102->AutoSize = true;
			this->label102->ForeColor = System::Drawing::Color::Magenta;
			this->label102->Location = System::Drawing::Point(267, 386);
			this->label102->Name = L"label102";
			this->label102->Size = System::Drawing::Size(72, 16);
			this->label102->TabIndex = 0;
			this->label102->Text = L"¬‡Î¸ÍÓ‚Ó";
			// 
			// barnaz1
			// 
			this->barnaz1->AutoSize = true;
			this->barnaz1->ForeColor = System::Drawing::Color::Navy;
			this->barnaz1->Location = System::Drawing::Point(466, 271);
			this->barnaz1->Name = L"barnaz1";
			this->barnaz1->Size = System::Drawing::Size(57, 16);
			this->barnaz1->TabIndex = 0;
			this->barnaz1->Text = L"«ËÏÌˇˇ";
			// 
			// comnaz3
			// 
			this->comnaz3->AutoSize = true;
			this->comnaz3->ForeColor = System::Drawing::Color::Green;
			this->comnaz3->Location = System::Drawing::Point(466, 114);
			this->comnaz3->Name = L"comnaz3";
			this->comnaz3->Size = System::Drawing::Size(72, 16);
			this->comnaz3->TabIndex = 0;
			this->comnaz3->Text = L"¬‡Î¸ÍÓ‚Ó";
			// 
			// valnaz3
			// 
			this->valnaz3->AutoSize = true;
			this->valnaz3->ForeColor = System::Drawing::Color::Magenta;
			this->valnaz3->Location = System::Drawing::Point(466, 446);
			this->valnaz3->Name = L"valnaz3";
			this->valnaz3->Size = System::Drawing::Size(73, 16);
			this->valnaz3->TabIndex = 0;
			this->valnaz3->Text = L" ÓÏ‡Ó‚Ó";
			// 
			// barnaz2
			// 
			this->barnaz2->AutoSize = true;
			this->barnaz2->ForeColor = System::Drawing::Color::Navy;
			this->barnaz2->Location = System::Drawing::Point(466, 301);
			this->barnaz2->Name = L"barnaz2";
			this->barnaz2->Size = System::Drawing::Size(72, 16);
			this->barnaz2->TabIndex = 0;
			this->barnaz2->Text = L"¬‡Î¸ÍÓ‚Ó";
			// 
			// valnaz1
			// 
			this->valnaz1->AutoSize = true;
			this->valnaz1->ForeColor = System::Drawing::Color::Magenta;
			this->valnaz1->Location = System::Drawing::Point(466, 386);
			this->valnaz1->Name = L"valnaz1";
			this->valnaz1->Size = System::Drawing::Size(64, 16);
			this->valnaz1->TabIndex = 0;
			this->valnaz1->Text = L"¡‡Ì‡ÛÎ";
			// 
			// barnaz3
			// 
			this->barnaz3->AutoSize = true;
			this->barnaz3->ForeColor = System::Drawing::Color::Navy;
			this->barnaz3->Location = System::Drawing::Point(466, 331);
			this->barnaz3->Name = L"barnaz3";
			this->barnaz3->Size = System::Drawing::Size(73, 16);
			this->barnaz3->TabIndex = 0;
			this->barnaz3->Text = L" ÓÏ‡Ó‚Ó";
			// 
			// label70
			// 
			this->label70->AutoSize = true;
			this->label70->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->label70->Location = System::Drawing::Point(267, 221);
			this->label70->Name = L"label70";
			this->label70->Size = System::Drawing::Size(57, 16);
			this->label70->TabIndex = 0;
			this->label70->Text = L"«ËÏÌˇˇ";
			// 
			// label69
			// 
			this->label69->AutoSize = true;
			this->label69->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->label69->Location = System::Drawing::Point(267, 191);
			this->label69->Name = L"label69";
			this->label69->Size = System::Drawing::Size(57, 16);
			this->label69->TabIndex = 0;
			this->label69->Text = L"«ËÏÌˇˇ";
			// 
			// label66
			// 
			this->label66->AutoSize = true;
			this->label66->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->label66->Location = System::Drawing::Point(267, 161);
			this->label66->Name = L"label66";
			this->label66->Size = System::Drawing::Size(57, 16);
			this->label66->TabIndex = 0;
			this->label66->Text = L"«ËÏÌˇˇ";
			// 
			// comnaz1
			// 
			this->comnaz1->AutoSize = true;
			this->comnaz1->ForeColor = System::Drawing::Color::Green;
			this->comnaz1->Location = System::Drawing::Point(466, 54);
			this->comnaz1->Name = L"comnaz1";
			this->comnaz1->Size = System::Drawing::Size(57, 16);
			this->comnaz1->TabIndex = 0;
			this->comnaz1->Text = L"«ËÏÌˇˇ";
			// 
			// label58
			// 
			this->label58->AutoSize = true;
			this->label58->ForeColor = System::Drawing::Color::Green;
			this->label58->Location = System::Drawing::Point(267, 114);
			this->label58->Name = L"label58";
			this->label58->Size = System::Drawing::Size(73, 16);
			this->label58->TabIndex = 0;
			this->label58->Text = L" ÓÏ‡Ó‚Ó";
			// 
			// label39
			// 
			this->label39->AutoSize = true;
			this->label39->ForeColor = System::Drawing::Color::Green;
			this->label39->Location = System::Drawing::Point(267, 84);
			this->label39->Name = L"label39";
			this->label39->Size = System::Drawing::Size(73, 16);
			this->label39->TabIndex = 0;
			this->label39->Text = L" ÓÏ‡Ó‚Ó";
			// 
			// zimnaz1
			// 
			this->zimnaz1->AutoSize = true;
			this->zimnaz1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->zimnaz1->Location = System::Drawing::Point(466, 161);
			this->zimnaz1->Name = L"zimnaz1";
			this->zimnaz1->Size = System::Drawing::Size(64, 16);
			this->zimnaz1->TabIndex = 0;
			this->zimnaz1->Text = L"¡‡Ì‡ÛÎ";
			// 
			// zimnaz3
			// 
			this->zimnaz3->AutoSize = true;
			this->zimnaz3->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->zimnaz3->Location = System::Drawing::Point(466, 221);
			this->zimnaz3->Name = L"zimnaz3";
			this->zimnaz3->Size = System::Drawing::Size(73, 16);
			this->zimnaz3->TabIndex = 0;
			this->zimnaz3->Text = L" ÓÏ‡Ó‚Ó";
			// 
			// label33
			// 
			this->label33->AutoSize = true;
			this->label33->ForeColor = System::Drawing::Color::Green;
			this->label33->Location = System::Drawing::Point(267, 54);
			this->label33->Name = L"label33";
			this->label33->Size = System::Drawing::Size(73, 16);
			this->label33->TabIndex = 0;
			this->label33->Text = L" ÓÏ‡Ó‚Ó";
			// 
			// label86
			// 
			this->label86->AutoSize = true;
			this->label86->ForeColor = System::Drawing::Color::Navy;
			this->label86->Location = System::Drawing::Point(267, 331);
			this->label86->Name = L"label86";
			this->label86->Size = System::Drawing::Size(64, 16);
			this->label86->TabIndex = 0;
			this->label86->Text = L"¡‡Ì‡ÛÎ";
			// 
			// label85
			// 
			this->label85->AutoSize = true;
			this->label85->ForeColor = System::Drawing::Color::Navy;
			this->label85->Location = System::Drawing::Point(267, 301);
			this->label85->Name = L"label85";
			this->label85->Size = System::Drawing::Size(64, 16);
			this->label85->TabIndex = 0;
			this->label85->Text = L"¡‡Ì‡ÛÎ";
			// 
			// label84
			// 
			this->label84->AutoSize = true;
			this->label84->ForeColor = System::Drawing::Color::Navy;
			this->label84->Location = System::Drawing::Point(267, 271);
			this->label84->Name = L"label84";
			this->label84->Size = System::Drawing::Size(64, 16);
			this->label84->TabIndex = 0;
			this->label84->Text = L"¡‡Ì‡ÛÎ";
			// 
			// comnaz2
			// 
			this->comnaz2->AutoSize = true;
			this->comnaz2->ForeColor = System::Drawing::Color::Green;
			this->comnaz2->Location = System::Drawing::Point(466, 84);
			this->comnaz2->Name = L"comnaz2";
			this->comnaz2->Size = System::Drawing::Size(64, 16);
			this->comnaz2->TabIndex = 0;
			this->comnaz2->Text = L"¡‡Ì‡ÛÎ";
			// 
			// valnaz2
			// 
			this->valnaz2->AutoSize = true;
			this->valnaz2->ForeColor = System::Drawing::Color::Magenta;
			this->valnaz2->Location = System::Drawing::Point(466, 416);
			this->valnaz2->Name = L"valnaz2";
			this->valnaz2->Size = System::Drawing::Size(57, 16);
			this->valnaz2->TabIndex = 0;
			this->valnaz2->Text = L"«ËÏÌˇˇ";
			// 
			// zimnaz2
			// 
			this->zimnaz2->AutoSize = true;
			this->zimnaz2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->zimnaz2->Location = System::Drawing::Point(466, 191);
			this->zimnaz2->Name = L"zimnaz2";
			this->zimnaz2->Size = System::Drawing::Size(72, 16);
			this->zimnaz2->TabIndex = 0;
			this->zimnaz2->Text = L"¬‡Î¸ÍÓ‚Ó";
			// 
			// tabPage1
			// 
			this->tabPage1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(187)), static_cast<System::Int32>(static_cast<System::Byte>(221)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->tabPage1->Controls->Add(this->label100);
			this->tabPage1->Controls->Add(this->tabControl1);
			this->tabPage1->Location = System::Drawing::Point(4, 25);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(1008, 620);
			this->tabPage1->TabIndex = 3;
			this->tabPage1->Text = L"—ÓÒÚÓˇÌËˇ ÔÓÂÁ‰Ó‚";
			this->tabPage1->ToolTipText = L"ÓÓÓ";
			// 
			// label100
			// 
			this->label100->AutoSize = true;
			this->label100->Font = (gcnew System::Drawing::Font(L"Courier New", 48, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label100->Location = System::Drawing::Point(146, 38);
			this->label100->Name = L"label100";
			this->label100->Size = System::Drawing::Size(716, 73);
			this->label100->TabIndex = 4;
			this->label100->Text = L"—ÓÒÚÓˇÌËˇ ÔÓÂÁ‰Ó‚:";
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage9);
			this->tabControl1->Controls->Add(this->tabPage10);
			this->tabControl1->Controls->Add(this->tabPage11);
			this->tabControl1->Controls->Add(this->tabPage12);
			this->tabControl1->Location = System::Drawing::Point(94, 149);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(828, 378);
			this->tabControl1->TabIndex = 3;
			// 
			// tabPage9
			// 
			this->tabPage9->BackColor = System::Drawing::Color::LightSteelBlue;
			this->tabPage9->Controls->Add(this->new1);
			this->tabPage9->Controls->Add(this->label41);
			this->tabPage9->Controls->Add(this->label48);
			this->tabPage9->Controls->Add(this->label46);
			this->tabPage9->Controls->Add(this->label40);
			this->tabPage9->Controls->Add(this->label159);
			this->tabPage9->Controls->Add(this->label44);
			this->tabPage9->Controls->Add(this->label43);
			this->tabPage9->Controls->Add(this->label42);
			this->tabPage9->Controls->Add(this->label36);
			this->tabPage9->Controls->Add(this->label23);
			this->tabPage9->Controls->Add(this->label34);
			this->tabPage9->Controls->Add(this->listBox28);
			this->tabPage9->Controls->Add(this->listBox3);
			this->tabPage9->Controls->Add(this->listBox1);
			this->tabPage9->Controls->Add(this->label158);
			this->tabPage9->Controls->Add(this->label38);
			this->tabPage9->Controls->Add(this->label35);
			this->tabPage9->Location = System::Drawing::Point(4, 25);
			this->tabPage9->Name = L"tabPage9";
			this->tabPage9->Padding = System::Windows::Forms::Padding(3);
			this->tabPage9->Size = System::Drawing::Size(820, 349);
			this->tabPage9->TabIndex = 0;
			this->tabPage9->Text = L"œÂ‚˚È ÔÓÂÁ‰";
			// 
			// new1
			// 
			this->new1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(187)), static_cast<System::Int32>(static_cast<System::Byte>(221)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->new1->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->new1->Location = System::Drawing::Point(622, 263);
			this->new1->Name = L"new1";
			this->new1->Size = System::Drawing::Size(121, 45);
			this->new1->TabIndex = 3;
			this->new1->Text = L"Œ·ÌÓ‚ËÚ¸";
			this->new1->UseVisualStyleBackColor = false;
			this->new1->Click += gcnew System::EventHandler(this, &Form1::new1_Click);
			// 
			// label41
			// 
			this->label41->AutoSize = true;
			this->label41->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label41->ForeColor = System::Drawing::Color::Red;
			this->label41->Location = System::Drawing::Point(658, 23);
			this->label41->Name = L"label41";
			this->label41->Size = System::Drawing::Size(120, 22);
			this->label41->TabIndex = 0;
			this->label41->Text = L"¬ÒÂ„Ó ÏÂÒÚ";
			// 
			// label48
			// 
			this->label48->AutoSize = true;
			this->label48->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label48->ForeColor = System::Drawing::Color::Red;
			this->label48->Location = System::Drawing::Point(412, 23);
			this->label48->Name = L"label48";
			this->label48->Size = System::Drawing::Size(164, 22);
			this->label48->TabIndex = 0;
			this->label48->Text = L"—‚Ó·Ó‰Ì˚ı ÏÂÒÚ";
			// 
			// label46
			// 
			this->label46->AutoSize = true;
			this->label46->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label46->ForeColor = System::Drawing::Color::Red;
			this->label46->Location = System::Drawing::Point(204, 23);
			this->label46->Name = L"label46";
			this->label46->Size = System::Drawing::Size(120, 22);
			this->label46->TabIndex = 0;
			this->label46->Text = L"“ËÔ ‚‡„ÓÌ‡";
			// 
			// label40
			// 
			this->label40->AutoSize = true;
			this->label40->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label40->ForeColor = System::Drawing::Color::Red;
			this->label40->Location = System::Drawing::Point(15, 23);
			this->label40->Name = L"label40";
			this->label40->Size = System::Drawing::Size(142, 22);
			this->label40->TabIndex = 0;
			this->label40->Text = L"ÕÓÏÂ ‚‡„ÓÌ‡";
			// 
			// label159
			// 
			this->label159->AutoSize = true;
			this->label159->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label159->Location = System::Drawing::Point(230, 263);
			this->label159->Name = L"label159";
			this->label159->Size = System::Drawing::Size(120, 22);
			this->label159->TabIndex = 0;
			this->label159->Text = L"ÏÂÒÚ ËÁ 40";
			// 
			// label44
			// 
			this->label44->AutoSize = true;
			this->label44->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label44->Location = System::Drawing::Point(206, 183);
			this->label44->Name = L"label44";
			this->label44->Size = System::Drawing::Size(54, 22);
			this->label44->TabIndex = 0;
			this->label44->Text = L" ÛÔÂ";
			// 
			// label43
			// 
			this->label43->AutoSize = true;
			this->label43->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label43->Location = System::Drawing::Point(206, 132);
			this->label43->Name = L"label43";
			this->label43->Size = System::Drawing::Size(164, 22);
			this->label43->TabIndex = 0;
			this->label43->Text = L"¬‡„ÓÌ-ÂÒÚÓ‡Ì";
			// 
			// label42
			// 
			this->label42->AutoSize = true;
			this->label42->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label42->Location = System::Drawing::Point(711, 83);
			this->label42->Name = L"label42";
			this->label42->Size = System::Drawing::Size(21, 22);
			this->label42->TabIndex = 0;
			this->label42->Text = L"4";
			// 
			// label36
			// 
			this->label36->AutoSize = true;
			this->label36->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label36->Location = System::Drawing::Point(711, 186);
			this->label36->Name = L"label36";
			this->label36->Size = System::Drawing::Size(32, 22);
			this->label36->TabIndex = 0;
			this->label36->Text = L"36";
			// 
			// label23
			// 
			this->label23->AutoSize = true;
			this->label23->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label23->Location = System::Drawing::Point(206, 80);
			this->label23->Name = L"label23";
			this->label23->Size = System::Drawing::Size(87, 22);
			this->label23->TabIndex = 0;
			this->label23->Text = L" ÛÔÂ+TV";
			// 
			// label34
			// 
			this->label34->AutoSize = true;
			this->label34->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label34->Location = System::Drawing::Point(17, 80);
			this->label34->Name = L"label34";
			this->label34->Size = System::Drawing::Size(87, 22);
			this->label34->TabIndex = 0;
			this->label34->Text = L"1 ‚‡„ÓÌ";
			// 
			// listBox28
			// 
			this->listBox28->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->listBox28->FormattingEnabled = true;
			this->listBox28->ItemHeight = 22;
			this->listBox28->Location = System::Drawing::Point(165, 259);
			this->listBox28->Name = L"listBox28";
			this->listBox28->Size = System::Drawing::Size(50, 26);
			this->listBox28->TabIndex = 2;
			// 
			// listBox3
			// 
			this->listBox3->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->listBox3->FormattingEnabled = true;
			this->listBox3->ItemHeight = 22;
			this->listBox3->Location = System::Drawing::Point(488, 179);
			this->listBox3->Name = L"listBox3";
			this->listBox3->Size = System::Drawing::Size(50, 26);
			this->listBox3->TabIndex = 2;
			// 
			// listBox1
			// 
			this->listBox1->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->listBox1->FormattingEnabled = true;
			this->listBox1->ItemHeight = 22;
			this->listBox1->Location = System::Drawing::Point(488, 79);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(50, 26);
			this->listBox1->TabIndex = 2;
			// 
			// label158
			// 
			this->label158->AutoSize = true;
			this->label158->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label158->Location = System::Drawing::Point(17, 263);
			this->label158->Name = L"label158";
			this->label158->Size = System::Drawing::Size(142, 22);
			this->label158->TabIndex = 0;
			this->label158->Text = L"»ÚÓ„Ó Á‡ÌˇÚÓ";
			// 
			// label38
			// 
			this->label38->AutoSize = true;
			this->label38->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label38->Location = System::Drawing::Point(17, 183);
			this->label38->Name = L"label38";
			this->label38->Size = System::Drawing::Size(87, 22);
			this->label38->TabIndex = 0;
			this->label38->Text = L"3 ‚‡„ÓÌ";
			// 
			// label35
			// 
			this->label35->AutoSize = true;
			this->label35->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label35->Location = System::Drawing::Point(17, 132);
			this->label35->Name = L"label35";
			this->label35->Size = System::Drawing::Size(87, 22);
			this->label35->TabIndex = 0;
			this->label35->Text = L"2 ‚‡„ÓÌ";
			// 
			// tabPage10
			// 
			this->tabPage10->BackColor = System::Drawing::Color::LightSteelBlue;
			this->tabPage10->Controls->Add(this->label160);
			this->tabPage10->Controls->Add(this->listBox29);
			this->tabPage10->Controls->Add(this->label161);
			this->tabPage10->Controls->Add(this->label63);
			this->tabPage10->Controls->Add(this->label64);
			this->tabPage10->Controls->Add(this->label47);
			this->tabPage10->Controls->Add(this->label49);
			this->tabPage10->Controls->Add(this->label50);
			this->tabPage10->Controls->Add(this->label51);
			this->tabPage10->Controls->Add(this->label55);
			this->tabPage10->Controls->Add(this->label56);
			this->tabPage10->Controls->Add(this->label62);
			this->tabPage10->Controls->Add(this->button2);
			this->tabPage10->Controls->Add(this->label57);
			this->tabPage10->Controls->Add(this->label60);
			this->tabPage10->Controls->Add(this->label61);
			this->tabPage10->Controls->Add(this->listBox5);
			this->tabPage10->Controls->Add(this->listBox7);
			this->tabPage10->Location = System::Drawing::Point(4, 25);
			this->tabPage10->Name = L"tabPage10";
			this->tabPage10->Padding = System::Windows::Forms::Padding(3);
			this->tabPage10->Size = System::Drawing::Size(820, 349);
			this->tabPage10->TabIndex = 1;
			this->tabPage10->Text = L"¬ÚÓÓÈ ÔÓÂÁ‰";
			// 
			// label160
			// 
			this->label160->AutoSize = true;
			this->label160->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label160->Location = System::Drawing::Point(230, 264);
			this->label160->Name = L"label160";
			this->label160->Size = System::Drawing::Size(120, 22);
			this->label160->TabIndex = 28;
			this->label160->Text = L"ÏÂÒÚ ËÁ 72";
			// 
			// listBox29
			// 
			this->listBox29->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->listBox29->FormattingEnabled = true;
			this->listBox29->ItemHeight = 22;
			this->listBox29->Location = System::Drawing::Point(165, 260);
			this->listBox29->Name = L"listBox29";
			this->listBox29->Size = System::Drawing::Size(50, 26);
			this->listBox29->TabIndex = 29;
			// 
			// label161
			// 
			this->label161->AutoSize = true;
			this->label161->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label161->Location = System::Drawing::Point(17, 264);
			this->label161->Name = L"label161";
			this->label161->Size = System::Drawing::Size(142, 22);
			this->label161->TabIndex = 27;
			this->label161->Text = L"»ÚÓ„Ó Á‡ÌˇÚÓ";
			// 
			// label63
			// 
			this->label63->AutoSize = true;
			this->label63->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label63->Location = System::Drawing::Point(688, 83);
			this->label63->Name = L"label63";
			this->label63->Size = System::Drawing::Size(32, 22);
			this->label63->TabIndex = 26;
			this->label63->Text = L"36";
			// 
			// label64
			// 
			this->label64->AutoSize = true;
			this->label64->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label64->Location = System::Drawing::Point(688, 186);
			this->label64->Name = L"label64";
			this->label64->Size = System::Drawing::Size(32, 22);
			this->label64->TabIndex = 25;
			this->label64->Text = L"36";
			// 
			// label47
			// 
			this->label47->AutoSize = true;
			this->label47->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label47->ForeColor = System::Drawing::Color::Red;
			this->label47->Location = System::Drawing::Point(660, 23);
			this->label47->Name = L"label47";
			this->label47->Size = System::Drawing::Size(120, 22);
			this->label47->TabIndex = 22;
			this->label47->Text = L"¬ÒÂ„Ó ÏÂÒÚ";
			// 
			// label49
			// 
			this->label49->AutoSize = true;
			this->label49->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label49->ForeColor = System::Drawing::Color::Red;
			this->label49->Location = System::Drawing::Point(414, 23);
			this->label49->Name = L"label49";
			this->label49->Size = System::Drawing::Size(164, 22);
			this->label49->TabIndex = 23;
			this->label49->Text = L"—‚Ó·Ó‰Ì˚ı ÏÂÒÚ";
			// 
			// label50
			// 
			this->label50->AutoSize = true;
			this->label50->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label50->ForeColor = System::Drawing::Color::Red;
			this->label50->Location = System::Drawing::Point(206, 23);
			this->label50->Name = L"label50";
			this->label50->Size = System::Drawing::Size(120, 22);
			this->label50->TabIndex = 24;
			this->label50->Text = L"“ËÔ ‚‡„ÓÌ‡";
			// 
			// label51
			// 
			this->label51->AutoSize = true;
			this->label51->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label51->ForeColor = System::Drawing::Color::Red;
			this->label51->Location = System::Drawing::Point(17, 23);
			this->label51->Name = L"label51";
			this->label51->Size = System::Drawing::Size(142, 22);
			this->label51->TabIndex = 19;
			this->label51->Text = L"ÕÓÏÂ ‚‡„ÓÌ‡";
			// 
			// label55
			// 
			this->label55->AutoSize = true;
			this->label55->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label55->Location = System::Drawing::Point(17, 80);
			this->label55->Name = L"label55";
			this->label55->Size = System::Drawing::Size(87, 22);
			this->label55->TabIndex = 18;
			this->label55->Text = L"1 ‚‡„ÓÌ";
			// 
			// label56
			// 
			this->label56->AutoSize = true;
			this->label56->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label56->Location = System::Drawing::Point(17, 183);
			this->label56->Name = L"label56";
			this->label56->Size = System::Drawing::Size(87, 22);
			this->label56->TabIndex = 21;
			this->label56->Text = L"3 ‚‡„ÓÌ";
			// 
			// label62
			// 
			this->label62->AutoSize = true;
			this->label62->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label62->Location = System::Drawing::Point(17, 132);
			this->label62->Name = L"label62";
			this->label62->Size = System::Drawing::Size(87, 22);
			this->label62->TabIndex = 20;
			this->label62->Text = L"2 ‚‡„ÓÌ";
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(187)), static_cast<System::Int32>(static_cast<System::Byte>(221)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->button2->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->button2->Location = System::Drawing::Point(638, 264);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(121, 45);
			this->button2->TabIndex = 17;
			this->button2->Text = L"Œ·ÌÓ‚ËÚ¸";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click_1);
			// 
			// label57
			// 
			this->label57->AutoSize = true;
			this->label57->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label57->Location = System::Drawing::Point(206, 183);
			this->label57->Name = L"label57";
			this->label57->Size = System::Drawing::Size(87, 22);
			this->label57->TabIndex = 9;
			this->label57->Text = L"—Ë‰ˇ˜ËÈ";
			// 
			// label60
			// 
			this->label60->AutoSize = true;
			this->label60->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label60->Location = System::Drawing::Point(206, 132);
			this->label60->Name = L"label60";
			this->label60->Size = System::Drawing::Size(164, 22);
			this->label60->TabIndex = 5;
			this->label60->Text = L"¬‡„ÓÌ-ÂÒÚÓ‡Ì";
			// 
			// label61
			// 
			this->label61->AutoSize = true;
			this->label61->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label61->Location = System::Drawing::Point(206, 80);
			this->label61->Name = L"label61";
			this->label61->Size = System::Drawing::Size(54, 22);
			this->label61->TabIndex = 4;
			this->label61->Text = L" ÛÔÂ";
			// 
			// listBox5
			// 
			this->listBox5->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->listBox5->FormattingEnabled = true;
			this->listBox5->ItemHeight = 22;
			this->listBox5->Location = System::Drawing::Point(488, 179);
			this->listBox5->Name = L"listBox5";
			this->listBox5->Size = System::Drawing::Size(50, 26);
			this->listBox5->TabIndex = 15;
			// 
			// listBox7
			// 
			this->listBox7->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->listBox7->FormattingEnabled = true;
			this->listBox7->ItemHeight = 22;
			this->listBox7->Location = System::Drawing::Point(488, 79);
			this->listBox7->Name = L"listBox7";
			this->listBox7->Size = System::Drawing::Size(50, 26);
			this->listBox7->TabIndex = 14;
			// 
			// tabPage11
			// 
			this->tabPage11->BackColor = System::Drawing::Color::LightSteelBlue;
			this->tabPage11->Controls->Add(this->label162);
			this->tabPage11->Controls->Add(this->listBox30);
			this->tabPage11->Controls->Add(this->label163);
			this->tabPage11->Controls->Add(this->label65);
			this->tabPage11->Controls->Add(this->label67);
			this->tabPage11->Controls->Add(this->label68);
			this->tabPage11->Controls->Add(this->label71);
			this->tabPage11->Controls->Add(this->label72);
			this->tabPage11->Controls->Add(this->label74);
			this->tabPage11->Controls->Add(this->label75);
			this->tabPage11->Controls->Add(this->label79);
			this->tabPage11->Controls->Add(this->label80);
			this->tabPage11->Controls->Add(this->button3);
			this->tabPage11->Controls->Add(this->label76);
			this->tabPage11->Controls->Add(this->label77);
			this->tabPage11->Controls->Add(this->label78);
			this->tabPage11->Controls->Add(this->listBox9);
			this->tabPage11->Controls->Add(this->listBox10);
			this->tabPage11->Location = System::Drawing::Point(4, 25);
			this->tabPage11->Name = L"tabPage11";
			this->tabPage11->Padding = System::Windows::Forms::Padding(3);
			this->tabPage11->Size = System::Drawing::Size(820, 349);
			this->tabPage11->TabIndex = 2;
			this->tabPage11->Text = L"“ÂÚËÈ ÔÓÂÁ‰";
			// 
			// label162
			// 
			this->label162->AutoSize = true;
			this->label162->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label162->Location = System::Drawing::Point(230, 264);
			this->label162->Name = L"label162";
			this->label162->Size = System::Drawing::Size(120, 22);
			this->label162->TabIndex = 38;
			this->label162->Text = L"ÏÂÒÚ ËÁ 72";
			// 
			// listBox30
			// 
			this->listBox30->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->listBox30->FormattingEnabled = true;
			this->listBox30->ItemHeight = 22;
			this->listBox30->Location = System::Drawing::Point(165, 260);
			this->listBox30->Name = L"listBox30";
			this->listBox30->Size = System::Drawing::Size(50, 26);
			this->listBox30->TabIndex = 39;
			// 
			// label163
			// 
			this->label163->AutoSize = true;
			this->label163->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label163->Location = System::Drawing::Point(17, 264);
			this->label163->Name = L"label163";
			this->label163->Size = System::Drawing::Size(142, 22);
			this->label163->TabIndex = 37;
			this->label163->Text = L"»ÚÓ„Ó Á‡ÌˇÚÓ";
			// 
			// label65
			// 
			this->label65->AutoSize = true;
			this->label65->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label65->Location = System::Drawing::Point(690, 80);
			this->label65->Name = L"label65";
			this->label65->Size = System::Drawing::Size(32, 22);
			this->label65->TabIndex = 36;
			this->label65->Text = L"36";
			// 
			// label67
			// 
			this->label67->AutoSize = true;
			this->label67->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label67->Location = System::Drawing::Point(690, 128);
			this->label67->Name = L"label67";
			this->label67->Size = System::Drawing::Size(32, 22);
			this->label67->TabIndex = 35;
			this->label67->Text = L"36";
			// 
			// label68
			// 
			this->label68->AutoSize = true;
			this->label68->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label68->ForeColor = System::Drawing::Color::Red;
			this->label68->Location = System::Drawing::Point(660, 23);
			this->label68->Name = L"label68";
			this->label68->Size = System::Drawing::Size(120, 22);
			this->label68->TabIndex = 32;
			this->label68->Text = L"¬ÒÂ„Ó ÏÂÒÚ";
			// 
			// label71
			// 
			this->label71->AutoSize = true;
			this->label71->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label71->ForeColor = System::Drawing::Color::Red;
			this->label71->Location = System::Drawing::Point(414, 23);
			this->label71->Name = L"label71";
			this->label71->Size = System::Drawing::Size(164, 22);
			this->label71->TabIndex = 33;
			this->label71->Text = L"—‚Ó·Ó‰Ì˚ı ÏÂÒÚ";
			// 
			// label72
			// 
			this->label72->AutoSize = true;
			this->label72->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label72->ForeColor = System::Drawing::Color::Red;
			this->label72->Location = System::Drawing::Point(206, 23);
			this->label72->Name = L"label72";
			this->label72->Size = System::Drawing::Size(120, 22);
			this->label72->TabIndex = 34;
			this->label72->Text = L"“ËÔ ‚‡„ÓÌ‡";
			// 
			// label74
			// 
			this->label74->AutoSize = true;
			this->label74->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label74->ForeColor = System::Drawing::Color::Red;
			this->label74->Location = System::Drawing::Point(17, 23);
			this->label74->Name = L"label74";
			this->label74->Size = System::Drawing::Size(142, 22);
			this->label74->TabIndex = 29;
			this->label74->Text = L"ÕÓÏÂ ‚‡„ÓÌ‡";
			// 
			// label75
			// 
			this->label75->AutoSize = true;
			this->label75->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label75->Location = System::Drawing::Point(17, 80);
			this->label75->Name = L"label75";
			this->label75->Size = System::Drawing::Size(87, 22);
			this->label75->TabIndex = 28;
			this->label75->Text = L"1 ‚‡„ÓÌ";
			// 
			// label79
			// 
			this->label79->AutoSize = true;
			this->label79->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label79->Location = System::Drawing::Point(17, 183);
			this->label79->Name = L"label79";
			this->label79->Size = System::Drawing::Size(87, 22);
			this->label79->TabIndex = 31;
			this->label79->Text = L"3 ‚‡„ÓÌ";
			// 
			// label80
			// 
			this->label80->AutoSize = true;
			this->label80->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label80->Location = System::Drawing::Point(17, 132);
			this->label80->Name = L"label80";
			this->label80->Size = System::Drawing::Size(87, 22);
			this->label80->TabIndex = 30;
			this->label80->Text = L"2 ‚‡„ÓÌ";
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(187)), static_cast<System::Int32>(static_cast<System::Byte>(221)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->button3->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->button3->Location = System::Drawing::Point(638, 264);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(121, 45);
			this->button3->TabIndex = 17;
			this->button3->Text = L"Œ·ÌÓ‚ËÚ¸";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// label76
			// 
			this->label76->AutoSize = true;
			this->label76->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label76->Location = System::Drawing::Point(206, 183);
			this->label76->Name = L"label76";
			this->label76->Size = System::Drawing::Size(98, 22);
			this->label76->TabIndex = 9;
			this->label76->Text = L"œÓ˜ÚÓ‚˚È";
			// 
			// label77
			// 
			this->label77->AutoSize = true;
			this->label77->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label77->Location = System::Drawing::Point(206, 128);
			this->label77->Name = L"label77";
			this->label77->Size = System::Drawing::Size(98, 22);
			this->label77->TabIndex = 5;
			this->label77->Text = L"œÎ‡ˆÍ‡Ú";
			// 
			// label78
			// 
			this->label78->AutoSize = true;
			this->label78->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label78->Location = System::Drawing::Point(206, 80);
			this->label78->Name = L"label78";
			this->label78->Size = System::Drawing::Size(98, 22);
			this->label78->TabIndex = 4;
			this->label78->Text = L"œÎ‡ˆÍ‡Ú";
			// 
			// listBox9
			// 
			this->listBox9->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->listBox9->FormattingEnabled = true;
			this->listBox9->ItemHeight = 22;
			this->listBox9->Location = System::Drawing::Point(488, 128);
			this->listBox9->Name = L"listBox9";
			this->listBox9->Size = System::Drawing::Size(50, 26);
			this->listBox9->TabIndex = 16;
			// 
			// listBox10
			// 
			this->listBox10->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->listBox10->FormattingEnabled = true;
			this->listBox10->ItemHeight = 22;
			this->listBox10->Location = System::Drawing::Point(488, 79);
			this->listBox10->Name = L"listBox10";
			this->listBox10->Size = System::Drawing::Size(50, 26);
			this->listBox10->TabIndex = 14;
			// 
			// tabPage12
			// 
			this->tabPage12->BackColor = System::Drawing::Color::LightSteelBlue;
			this->tabPage12->Controls->Add(this->label164);
			this->tabPage12->Controls->Add(this->listBox31);
			this->tabPage12->Controls->Add(this->label165);
			this->tabPage12->Controls->Add(this->label81);
			this->tabPage12->Controls->Add(this->label98);
			this->tabPage12->Controls->Add(this->label82);
			this->tabPage12->Controls->Add(this->label87);
			this->tabPage12->Controls->Add(this->label88);
			this->tabPage12->Controls->Add(this->label89);
			this->tabPage12->Controls->Add(this->label90);
			this->tabPage12->Controls->Add(this->label92);
			this->tabPage12->Controls->Add(this->label96);
			this->tabPage12->Controls->Add(this->label97);
			this->tabPage12->Controls->Add(this->button4);
			this->tabPage12->Controls->Add(this->label93);
			this->tabPage12->Controls->Add(this->label94);
			this->tabPage12->Controls->Add(this->label95);
			this->tabPage12->Controls->Add(this->listBox11);
			this->tabPage12->Controls->Add(this->listBox12);
			this->tabPage12->Controls->Add(this->listBox13);
			this->tabPage12->Location = System::Drawing::Point(4, 25);
			this->tabPage12->Name = L"tabPage12";
			this->tabPage12->Padding = System::Windows::Forms::Padding(3);
			this->tabPage12->Size = System::Drawing::Size(820, 349);
			this->tabPage12->TabIndex = 3;
			this->tabPage12->Text = L"◊ÂÚ‚ÂÚ˚È ÔÓÂÁ‰";
			// 
			// label164
			// 
			this->label164->AutoSize = true;
			this->label164->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label164->Location = System::Drawing::Point(230, 264);
			this->label164->Name = L"label164";
			this->label164->Size = System::Drawing::Size(120, 22);
			this->label164->TabIndex = 48;
			this->label164->Text = L"ÏÂÒÚ ËÁ 76";
			// 
			// listBox31
			// 
			this->listBox31->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->listBox31->FormattingEnabled = true;
			this->listBox31->ItemHeight = 22;
			this->listBox31->Location = System::Drawing::Point(165, 260);
			this->listBox31->Name = L"listBox31";
			this->listBox31->Size = System::Drawing::Size(50, 26);
			this->listBox31->TabIndex = 49;
			// 
			// label165
			// 
			this->label165->AutoSize = true;
			this->label165->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label165->Location = System::Drawing::Point(17, 264);
			this->label165->Name = L"label165";
			this->label165->Size = System::Drawing::Size(142, 22);
			this->label165->TabIndex = 47;
			this->label165->Text = L"»ÚÓ„Ó Á‡ÌˇÚÓ";
			// 
			// label81
			// 
			this->label81->AutoSize = true;
			this->label81->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label81->Location = System::Drawing::Point(690, 80);
			this->label81->Name = L"label81";
			this->label81->Size = System::Drawing::Size(32, 22);
			this->label81->TabIndex = 46;
			this->label81->Text = L"36";
			// 
			// label98
			// 
			this->label98->AutoSize = true;
			this->label98->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label98->Location = System::Drawing::Point(690, 183);
			this->label98->Name = L"label98";
			this->label98->Size = System::Drawing::Size(32, 22);
			this->label98->TabIndex = 45;
			this->label98->Text = L"36";
			// 
			// label82
			// 
			this->label82->AutoSize = true;
			this->label82->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label82->Location = System::Drawing::Point(690, 128);
			this->label82->Name = L"label82";
			this->label82->Size = System::Drawing::Size(21, 22);
			this->label82->TabIndex = 45;
			this->label82->Text = L"4";
			// 
			// label87
			// 
			this->label87->AutoSize = true;
			this->label87->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label87->ForeColor = System::Drawing::Color::Red;
			this->label87->Location = System::Drawing::Point(660, 23);
			this->label87->Name = L"label87";
			this->label87->Size = System::Drawing::Size(120, 22);
			this->label87->TabIndex = 42;
			this->label87->Text = L"¬ÒÂ„Ó ÏÂÒÚ";
			// 
			// label88
			// 
			this->label88->AutoSize = true;
			this->label88->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label88->ForeColor = System::Drawing::Color::Red;
			this->label88->Location = System::Drawing::Point(414, 23);
			this->label88->Name = L"label88";
			this->label88->Size = System::Drawing::Size(164, 22);
			this->label88->TabIndex = 43;
			this->label88->Text = L"—‚Ó·Ó‰Ì˚ı ÏÂÒÚ";
			// 
			// label89
			// 
			this->label89->AutoSize = true;
			this->label89->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label89->ForeColor = System::Drawing::Color::Red;
			this->label89->Location = System::Drawing::Point(206, 23);
			this->label89->Name = L"label89";
			this->label89->Size = System::Drawing::Size(120, 22);
			this->label89->TabIndex = 44;
			this->label89->Text = L"“ËÔ ‚‡„ÓÌ‡";
			// 
			// label90
			// 
			this->label90->AutoSize = true;
			this->label90->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label90->ForeColor = System::Drawing::Color::Red;
			this->label90->Location = System::Drawing::Point(17, 23);
			this->label90->Name = L"label90";
			this->label90->Size = System::Drawing::Size(142, 22);
			this->label90->TabIndex = 39;
			this->label90->Text = L"ÕÓÏÂ ‚‡„ÓÌ‡";
			// 
			// label92
			// 
			this->label92->AutoSize = true;
			this->label92->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label92->Location = System::Drawing::Point(17, 80);
			this->label92->Name = L"label92";
			this->label92->Size = System::Drawing::Size(87, 22);
			this->label92->TabIndex = 38;
			this->label92->Text = L"1 ‚‡„ÓÌ";
			// 
			// label96
			// 
			this->label96->AutoSize = true;
			this->label96->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label96->Location = System::Drawing::Point(17, 183);
			this->label96->Name = L"label96";
			this->label96->Size = System::Drawing::Size(87, 22);
			this->label96->TabIndex = 41;
			this->label96->Text = L"3 ‚‡„ÓÌ";
			// 
			// label97
			// 
			this->label97->AutoSize = true;
			this->label97->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label97->Location = System::Drawing::Point(17, 132);
			this->label97->Name = L"label97";
			this->label97->Size = System::Drawing::Size(87, 22);
			this->label97->TabIndex = 40;
			this->label97->Text = L"2 ‚‡„ÓÌ";
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(187)), static_cast<System::Int32>(static_cast<System::Byte>(221)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->button4->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->button4->Location = System::Drawing::Point(638, 264);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(126, 42);
			this->button4->TabIndex = 17;
			this->button4->Text = L"Œ·ÌÓ‚ËÚ¸";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
			// 
			// label93
			// 
			this->label93->AutoSize = true;
			this->label93->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label93->Location = System::Drawing::Point(206, 183);
			this->label93->Name = L"label93";
			this->label93->Size = System::Drawing::Size(98, 22);
			this->label93->TabIndex = 9;
			this->label93->Text = L" ÛÔÂ+tel";
			// 
			// label94
			// 
			this->label94->AutoSize = true;
			this->label94->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label94->Location = System::Drawing::Point(206, 132);
			this->label94->Name = L"label94";
			this->label94->Size = System::Drawing::Size(87, 22);
			this->label94->TabIndex = 5;
			this->label94->Text = L" ÛÔÂ+TV";
			// 
			// label95
			// 
			this->label95->AutoSize = true;
			this->label95->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label95->Location = System::Drawing::Point(206, 80);
			this->label95->Name = L"label95";
			this->label95->Size = System::Drawing::Size(54, 22);
			this->label95->TabIndex = 4;
			this->label95->Text = L" ÛÔÂ";
			// 
			// listBox11
			// 
			this->listBox11->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->listBox11->FormattingEnabled = true;
			this->listBox11->ItemHeight = 22;
			this->listBox11->Location = System::Drawing::Point(488, 179);
			this->listBox11->Name = L"listBox11";
			this->listBox11->Size = System::Drawing::Size(50, 26);
			this->listBox11->TabIndex = 15;
			// 
			// listBox12
			// 
			this->listBox12->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->listBox12->FormattingEnabled = true;
			this->listBox12->ItemHeight = 22;
			this->listBox12->Location = System::Drawing::Point(488, 128);
			this->listBox12->Name = L"listBox12";
			this->listBox12->Size = System::Drawing::Size(50, 26);
			this->listBox12->TabIndex = 16;
			// 
			// listBox13
			// 
			this->listBox13->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->listBox13->FormattingEnabled = true;
			this->listBox13->ItemHeight = 22;
			this->listBox13->Location = System::Drawing::Point(488, 79);
			this->listBox13->Name = L"listBox13";
			this->listBox13->Size = System::Drawing::Size(50, 26);
			this->listBox13->TabIndex = 14;
			// 
			// tabPage6
			// 
			this->tabPage6->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(187)), static_cast<System::Int32>(static_cast<System::Byte>(221)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->tabPage6->Controls->Add(this->label171);
			this->tabPage6->Controls->Add(this->panel1);
			this->tabPage6->Location = System::Drawing::Point(4, 25);
			this->tabPage6->Name = L"tabPage6";
			this->tabPage6->Padding = System::Windows::Forms::Padding(3);
			this->tabPage6->Size = System::Drawing::Size(1008, 620);
			this->tabPage6->TabIndex = 6;
			this->tabPage6->Text = L"«‡„ÛÊÂÌÌÓÒÚ¸ ‚‡„ÓÌÓ‚";
			// 
			// label171
			// 
			this->label171->AutoSize = true;
			this->label171->Font = (gcnew System::Drawing::Font(L"Courier New", 48, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label171->Location = System::Drawing::Point(96, 75);
			this->label171->Name = L"label171";
			this->label171->Size = System::Drawing::Size(868, 73);
			this->label171->TabIndex = 8;
			this->label171->Text = L"«‡„ÛÊÂÌÌÓÒÚ¸ ‚‡„ÓÌÓ‚:";
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::LightSteelBlue;
			this->panel1->Controls->Add(this->button5);
			this->panel1->Controls->Add(this->listBox15);
			this->panel1->Controls->Add(this->listBox6);
			this->panel1->Controls->Add(this->listBox2);
			this->panel1->Controls->Add(this->listBox8);
			this->panel1->Controls->Add(this->listBox4);
			this->panel1->Controls->Add(this->label106);
			this->panel1->Controls->Add(this->label109);
			this->panel1->Controls->Add(this->label113);
			this->panel1->Controls->Add(this->label110);
			this->panel1->Controls->Add(this->label107);
			this->panel1->Controls->Add(this->label105);
			this->panel1->Controls->Add(this->label117);
			this->panel1->Location = System::Drawing::Point(182, 189);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(625, 290);
			this->panel1->TabIndex = 7;
			// 
			// button5
			// 
			this->button5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(187)), static_cast<System::Int32>(static_cast<System::Byte>(221)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->button5->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->button5->Location = System::Drawing::Point(471, 215);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(121, 45);
			this->button5->TabIndex = 9;
			this->button5->Text = L"Œ·ÌÓ‚ËÚ¸";
			this->button5->UseVisualStyleBackColor = false;
			this->button5->Click += gcnew System::EventHandler(this, &Form1::button5_Click);
			// 
			// listBox15
			// 
			this->listBox15->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->listBox15->FormattingEnabled = true;
			this->listBox15->ItemHeight = 18;
			this->listBox15->Location = System::Drawing::Point(278, 186);
			this->listBox15->Name = L"listBox15";
			this->listBox15->Size = System::Drawing::Size(50, 22);
			this->listBox15->TabIndex = 2;
			// 
			// listBox6
			// 
			this->listBox6->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->listBox6->FormattingEnabled = true;
			this->listBox6->ItemHeight = 18;
			this->listBox6->Location = System::Drawing::Point(278, 96);
			this->listBox6->Name = L"listBox6";
			this->listBox6->Size = System::Drawing::Size(50, 22);
			this->listBox6->TabIndex = 2;
			// 
			// listBox2
			// 
			this->listBox2->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->listBox2->FormattingEnabled = true;
			this->listBox2->ItemHeight = 18;
			this->listBox2->Location = System::Drawing::Point(278, 126);
			this->listBox2->Name = L"listBox2";
			this->listBox2->Size = System::Drawing::Size(50, 22);
			this->listBox2->TabIndex = 2;
			// 
			// listBox8
			// 
			this->listBox8->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->listBox8->FormattingEnabled = true;
			this->listBox8->ItemHeight = 18;
			this->listBox8->Location = System::Drawing::Point(278, 156);
			this->listBox8->Name = L"listBox8";
			this->listBox8->Size = System::Drawing::Size(50, 22);
			this->listBox8->TabIndex = 2;
			// 
			// listBox4
			// 
			this->listBox4->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->listBox4->FormattingEnabled = true;
			this->listBox4->ItemHeight = 18;
			this->listBox4->Location = System::Drawing::Point(278, 66);
			this->listBox4->Name = L"listBox4";
			this->listBox4->Size = System::Drawing::Size(50, 22);
			this->listBox4->TabIndex = 2;
			// 
			// label106
			// 
			this->label106->AutoSize = true;
			this->label106->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label106->ForeColor = System::Drawing::Color::Red;
			this->label106->Location = System::Drawing::Point(274, 17);
			this->label106->Name = L"label106";
			this->label106->Size = System::Drawing::Size(318, 22);
			this->label106->TabIndex = 0;
			this->label106->Text = L" ÓÎË˜ÂÒÚ‚Ó ÍÛÔÎÂÌÌ˚ı ·ËÎÂÚÓ‚";
			// 
			// label109
			// 
			this->label109->AutoSize = true;
			this->label109->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label109->ForeColor = System::Drawing::Color::Red;
			this->label109->Location = System::Drawing::Point(35, 17);
			this->label109->Name = L"label109";
			this->label109->Size = System::Drawing::Size(120, 22);
			this->label109->TabIndex = 0;
			this->label109->Text = L"“ËÔ ‚‡„ÓÌ‡";
			// 
			// label113
			// 
			this->label113->AutoSize = true;
			this->label113->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label113->Location = System::Drawing::Point(36, 190);
			this->label113->Name = L"label113";
			this->label113->Size = System::Drawing::Size(208, 18);
			this->label113->TabIndex = 0;
			this->label113->Text = L" ÛÔÂÈÌ˚Â Ò ÚÂÎÂÙÓÌÓÏ";
			// 
			// label110
			// 
			this->label110->AutoSize = true;
			this->label110->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label110->Location = System::Drawing::Point(36, 160);
			this->label110->Name = L"label110";
			this->label110->Size = System::Drawing::Size(228, 18);
			this->label110->TabIndex = 0;
			this->label110->Text = L" ÛÔÂÈÌ˚Â Ò ÚÂÎÂ‚ËÁÓÓÏ";
			// 
			// label107
			// 
			this->label107->AutoSize = true;
			this->label107->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label107->Location = System::Drawing::Point(36, 130);
			this->label107->Name = L"label107";
			this->label107->Size = System::Drawing::Size(88, 18);
			this->label107->TabIndex = 0;
			this->label107->Text = L" ÛÔÂÈÌ˚Â";
			// 
			// label105
			// 
			this->label105->AutoSize = true;
			this->label105->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label105->Location = System::Drawing::Point(36, 100);
			this->label105->Name = L"label105";
			this->label105->Size = System::Drawing::Size(118, 18);
			this->label105->TabIndex = 0;
			this->label105->Text = L"œÎ‡ˆÍ‡ÚÌ˚Â";
			// 
			// label117
			// 
			this->label117->AutoSize = true;
			this->label117->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label117->Location = System::Drawing::Point(36, 70);
			this->label117->Name = L"label117";
			this->label117->Size = System::Drawing::Size(78, 18);
			this->label117->TabIndex = 0;
			this->label117->Text = L"—Ë‰ˇ˜ËÂ";
			// 
			// tabPage5
			// 
			this->tabPage5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(187)), static_cast<System::Int32>(static_cast<System::Byte>(221)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->tabPage5->Controls->Add(this->label101);
			this->tabPage5->Controls->Add(this->panel5);
			this->tabPage5->Location = System::Drawing::Point(4, 25);
			this->tabPage5->Name = L"tabPage5";
			this->tabPage5->Padding = System::Windows::Forms::Padding(3);
			this->tabPage5->Size = System::Drawing::Size(1008, 620);
			this->tabPage5->TabIndex = 5;
			this->tabPage5->Text = L"«‡„ÛÊÂÌÌÓÒÚ¸ Ï‡¯ÛÚÓ‚";
			// 
			// label101
			// 
			this->label101->AutoSize = true;
			this->label101->Font = (gcnew System::Drawing::Font(L"Courier New", 48, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label101->Location = System::Drawing::Point(45, 17);
			this->label101->Name = L"label101";
			this->label101->Size = System::Drawing::Size(944, 73);
			this->label101->TabIndex = 9;
			this->label101->Text = L"«‡„ÛÊÂÌÌÓÒÚ¸ Ï‡¯ÛÚÓ‚:";
			// 
			// panel5
			// 
			this->panel5->BackColor = System::Drawing::Color::LightSteelBlue;
			this->panel5->Controls->Add(this->button7);
			this->panel5->Controls->Add(this->label122);
			this->panel5->Controls->Add(this->label123);
			this->panel5->Controls->Add(this->label124);
			this->panel5->Controls->Add(this->label125);
			this->panel5->Controls->Add(this->label126);
			this->panel5->Controls->Add(this->label127);
			this->panel5->Controls->Add(this->listBox22);
			this->panel5->Controls->Add(this->listBox23);
			this->panel5->Controls->Add(this->listBox24);
			this->panel5->Controls->Add(this->listBox25);
			this->panel5->Controls->Add(this->listBox26);
			this->panel5->Controls->Add(this->listBox27);
			this->panel5->Controls->Add(this->listBox32);
			this->panel5->Controls->Add(this->listBox33);
			this->panel5->Controls->Add(this->listBox34);
			this->panel5->Controls->Add(this->listBox35);
			this->panel5->Controls->Add(this->listBox36);
			this->panel5->Controls->Add(this->listBox37);
			this->panel5->Controls->Add(this->label128);
			this->panel5->Controls->Add(this->label129);
			this->panel5->Controls->Add(this->label130);
			this->panel5->Controls->Add(this->label131);
			this->panel5->Controls->Add(this->label132);
			this->panel5->Controls->Add(this->label133);
			this->panel5->Controls->Add(this->label134);
			this->panel5->Controls->Add(this->label135);
			this->panel5->Location = System::Drawing::Point(189, 93);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(623, 492);
			this->panel5->TabIndex = 8;
			// 
			// button7
			// 
			this->button7->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(187)), static_cast<System::Int32>(static_cast<System::Byte>(221)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->button7->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->button7->Location = System::Drawing::Point(459, 421);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(121, 45);
			this->button7->TabIndex = 9;
			this->button7->Text = L"Œ·ÌÓ‚ËÚ¸";
			this->button7->UseVisualStyleBackColor = false;
			this->button7->Click += gcnew System::EventHandler(this, &Form1::button7_Click);
			// 
			// label122
			// 
			this->label122->AutoSize = true;
			this->label122->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label122->Location = System::Drawing::Point(36, 418);
			this->label122->Name = L"label122";
			this->label122->Size = System::Drawing::Size(178, 18);
			this->label122->TabIndex = 6;
			this->label122->Text = L"¬‡Î¸ÍÓ‚Ó - «ËÏÌˇˇ";
			// 
			// label123
			// 
			this->label123->AutoSize = true;
			this->label123->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label123->Location = System::Drawing::Point(36, 448);
			this->label123->Name = L"label123";
			this->label123->Size = System::Drawing::Size(188, 18);
			this->label123->TabIndex = 7;
			this->label123->Text = L"¬‡Î¸ÍÓ‚Ó - ¡‡Ì‡ÛÎ";
			// 
			// label124
			// 
			this->label124->AutoSize = true;
			this->label124->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label124->Location = System::Drawing::Point(36, 388);
			this->label124->Name = L"label124";
			this->label124->Size = System::Drawing::Size(198, 18);
			this->label124->TabIndex = 8;
			this->label124->Text = L"¬‡Î¸ÍÓ‚Ó -  ÓÏ‡Ó‚Ó";
			// 
			// label125
			// 
			this->label125->AutoSize = true;
			this->label125->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label125->Location = System::Drawing::Point(36, 338);
			this->label125->Name = L"label125";
			this->label125->Size = System::Drawing::Size(188, 18);
			this->label125->TabIndex = 3;
			this->label125->Text = L"¡‡Ì‡ÛÎ - ¬‡Î¸ÍÓ‚Ó";
			// 
			// label126
			// 
			this->label126->AutoSize = true;
			this->label126->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label126->Location = System::Drawing::Point(36, 308);
			this->label126->Name = L"label126";
			this->label126->Size = System::Drawing::Size(168, 18);
			this->label126->TabIndex = 4;
			this->label126->Text = L"¡‡Ì‡ÛÎ - «ËÏÌˇˇ";
			// 
			// label127
			// 
			this->label127->AutoSize = true;
			this->label127->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label127->Location = System::Drawing::Point(36, 278);
			this->label127->Name = L"label127";
			this->label127->Size = System::Drawing::Size(188, 18);
			this->label127->TabIndex = 5;
			this->label127->Text = L"¡‡Ì‡ÛÎ -  ÓÏ‡Ó‚Ó";
			// 
			// listBox22
			// 
			this->listBox22->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->listBox22->FormattingEnabled = true;
			this->listBox22->ItemHeight = 18;
			this->listBox22->Location = System::Drawing::Point(266, 414);
			this->listBox22->Name = L"listBox22";
			this->listBox22->Size = System::Drawing::Size(50, 22);
			this->listBox22->TabIndex = 2;
			// 
			// listBox23
			// 
			this->listBox23->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->listBox23->FormattingEnabled = true;
			this->listBox23->ItemHeight = 18;
			this->listBox23->Location = System::Drawing::Point(266, 304);
			this->listBox23->Name = L"listBox23";
			this->listBox23->Size = System::Drawing::Size(50, 22);
			this->listBox23->TabIndex = 2;
			// 
			// listBox24
			// 
			this->listBox24->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->listBox24->FormattingEnabled = true;
			this->listBox24->ItemHeight = 18;
			this->listBox24->Location = System::Drawing::Point(266, 194);
			this->listBox24->Name = L"listBox24";
			this->listBox24->Size = System::Drawing::Size(50, 22);
			this->listBox24->TabIndex = 2;
			// 
			// listBox25
			// 
			this->listBox25->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->listBox25->FormattingEnabled = true;
			this->listBox25->ItemHeight = 18;
			this->listBox25->Location = System::Drawing::Point(266, 84);
			this->listBox25->Name = L"listBox25";
			this->listBox25->Size = System::Drawing::Size(50, 22);
			this->listBox25->TabIndex = 2;
			// 
			// listBox26
			// 
			this->listBox26->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->listBox26->FormattingEnabled = true;
			this->listBox26->ItemHeight = 18;
			this->listBox26->Location = System::Drawing::Point(266, 444);
			this->listBox26->Name = L"listBox26";
			this->listBox26->Size = System::Drawing::Size(50, 22);
			this->listBox26->TabIndex = 2;
			// 
			// listBox27
			// 
			this->listBox27->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->listBox27->FormattingEnabled = true;
			this->listBox27->ItemHeight = 18;
			this->listBox27->Location = System::Drawing::Point(266, 334);
			this->listBox27->Name = L"listBox27";
			this->listBox27->Size = System::Drawing::Size(50, 22);
			this->listBox27->TabIndex = 2;
			// 
			// listBox32
			// 
			this->listBox32->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->listBox32->FormattingEnabled = true;
			this->listBox32->ItemHeight = 18;
			this->listBox32->Location = System::Drawing::Point(266, 224);
			this->listBox32->Name = L"listBox32";
			this->listBox32->Size = System::Drawing::Size(50, 22);
			this->listBox32->TabIndex = 2;
			// 
			// listBox33
			// 
			this->listBox33->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->listBox33->FormattingEnabled = true;
			this->listBox33->ItemHeight = 18;
			this->listBox33->Location = System::Drawing::Point(266, 114);
			this->listBox33->Name = L"listBox33";
			this->listBox33->Size = System::Drawing::Size(50, 22);
			this->listBox33->TabIndex = 2;
			// 
			// listBox34
			// 
			this->listBox34->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->listBox34->FormattingEnabled = true;
			this->listBox34->ItemHeight = 18;
			this->listBox34->Location = System::Drawing::Point(266, 384);
			this->listBox34->Name = L"listBox34";
			this->listBox34->Size = System::Drawing::Size(50, 22);
			this->listBox34->TabIndex = 2;
			// 
			// listBox35
			// 
			this->listBox35->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->listBox35->FormattingEnabled = true;
			this->listBox35->ItemHeight = 18;
			this->listBox35->Location = System::Drawing::Point(266, 274);
			this->listBox35->Name = L"listBox35";
			this->listBox35->Size = System::Drawing::Size(50, 22);
			this->listBox35->TabIndex = 2;
			// 
			// listBox36
			// 
			this->listBox36->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->listBox36->FormattingEnabled = true;
			this->listBox36->ItemHeight = 18;
			this->listBox36->Location = System::Drawing::Point(266, 164);
			this->listBox36->Name = L"listBox36";
			this->listBox36->Size = System::Drawing::Size(50, 22);
			this->listBox36->TabIndex = 2;
			// 
			// listBox37
			// 
			this->listBox37->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->listBox37->FormattingEnabled = true;
			this->listBox37->ItemHeight = 18;
			this->listBox37->Location = System::Drawing::Point(266, 54);
			this->listBox37->Name = L"listBox37";
			this->listBox37->Size = System::Drawing::Size(50, 22);
			this->listBox37->TabIndex = 2;
			// 
			// label128
			// 
			this->label128->AutoSize = true;
			this->label128->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label128->ForeColor = System::Drawing::Color::Red;
			this->label128->Location = System::Drawing::Point(262, 17);
			this->label128->Name = L"label128";
			this->label128->Size = System::Drawing::Size(318, 22);
			this->label128->TabIndex = 0;
			this->label128->Text = L" ÓÎË˜ÂÒÚ‚Ó ÍÛÔÎÂÌÌ˚ı ·ËÎÂÚÓ‚";
			// 
			// label129
			// 
			this->label129->AutoSize = true;
			this->label129->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label129->ForeColor = System::Drawing::Color::Red;
			this->label129->Location = System::Drawing::Point(35, 17);
			this->label129->Name = L"label129";
			this->label129->Size = System::Drawing::Size(87, 22);
			this->label129->TabIndex = 0;
			this->label129->Text = L"Ã‡¯ÛÚ";
			// 
			// label130
			// 
			this->label130->AutoSize = true;
			this->label130->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label130->Location = System::Drawing::Point(36, 198);
			this->label130->Name = L"label130";
			this->label130->Size = System::Drawing::Size(168, 18);
			this->label130->TabIndex = 0;
			this->label130->Text = L"«ËÏÌˇˇ - ¡‡Ì‡ÛÎ";
			// 
			// label131
			// 
			this->label131->AutoSize = true;
			this->label131->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label131->Location = System::Drawing::Point(36, 228);
			this->label131->Name = L"label131";
			this->label131->Size = System::Drawing::Size(178, 18);
			this->label131->TabIndex = 0;
			this->label131->Text = L"«ËÏÌˇˇ - ¬‡Î¸ÍÓ‚Ó";
			// 
			// label132
			// 
			this->label132->AutoSize = true;
			this->label132->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label132->Location = System::Drawing::Point(36, 168);
			this->label132->Name = L"label132";
			this->label132->Size = System::Drawing::Size(178, 18);
			this->label132->TabIndex = 0;
			this->label132->Text = L"«ËÏÌˇˇ -  ÓÏ‡Ó‚Ó";
			// 
			// label133
			// 
			this->label133->AutoSize = true;
			this->label133->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label133->Location = System::Drawing::Point(36, 118);
			this->label133->Name = L"label133";
			this->label133->Size = System::Drawing::Size(198, 18);
			this->label133->TabIndex = 0;
			this->label133->Text = L" ÓÏ‡Ó‚Ó - ¬‡Î¸ÍÓ‚Ó";
			// 
			// label134
			// 
			this->label134->AutoSize = true;
			this->label134->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label134->Location = System::Drawing::Point(36, 88);
			this->label134->Name = L"label134";
			this->label134->Size = System::Drawing::Size(188, 18);
			this->label134->TabIndex = 0;
			this->label134->Text = L" ÓÏ‡Ó‚Ó - ¡‡Ì‡ÛÎ";
			// 
			// label135
			// 
			this->label135->AutoSize = true;
			this->label135->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label135->Location = System::Drawing::Point(36, 58);
			this->label135->Name = L"label135";
			this->label135->Size = System::Drawing::Size(178, 18);
			this->label135->TabIndex = 0;
			this->label135->Text = L" ÓÏ‡Ó‚Ó - «ËÏÌˇˇ";
			// 
			// tabPage7
			// 
			this->tabPage7->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(187)), static_cast<System::Int32>(static_cast<System::Byte>(221)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->tabPage7->Controls->Add(this->label157);
			this->tabPage7->Controls->Add(this->tabControl2);
			this->tabPage7->Location = System::Drawing::Point(4, 25);
			this->tabPage7->Name = L"tabPage7";
			this->tabPage7->Padding = System::Windows::Forms::Padding(3);
			this->tabPage7->Size = System::Drawing::Size(1008, 620);
			this->tabPage7->TabIndex = 7;
			this->tabPage7->Text = L"¬˚Û˜Í‡";
			// 
			// label157
			// 
			this->label157->AutoSize = true;
			this->label157->Font = (gcnew System::Drawing::Font(L"Courier New", 48, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label157->Location = System::Drawing::Point(351, 28);
			this->label157->Name = L"label157";
			this->label157->Size = System::Drawing::Size(298, 73);
			this->label157->TabIndex = 10;
			this->label157->Text = L"¬˚Û˜Í‡";
			// 
			// tabControl2
			// 
			this->tabControl2->Controls->Add(this->tabPage2);
			this->tabControl2->Controls->Add(this->tabPage13);
			this->tabControl2->Controls->Add(this->tabPage15);
			this->tabControl2->Location = System::Drawing::Point(241, 122);
			this->tabControl2->Name = L"tabControl2";
			this->tabControl2->SelectedIndex = 0;
			this->tabControl2->Size = System::Drawing::Size(528, 366);
			this->tabControl2->TabIndex = 4;
			// 
			// tabPage2
			// 
			this->tabPage2->BackColor = System::Drawing::Color::LightSteelBlue;
			this->tabPage2->Controls->Add(this->button8);
			this->tabPage2->Controls->Add(this->label116);
			this->tabPage2->Controls->Add(this->label118);
			this->tabPage2->Controls->Add(this->label136);
			this->tabPage2->Controls->Add(this->label111);
			this->tabPage2->Controls->Add(this->label121);
			this->tabPage2->Controls->Add(this->label115);
			this->tabPage2->Controls->Add(this->label119);
			this->tabPage2->Controls->Add(this->label139);
			this->tabPage2->Controls->Add(this->listBox14);
			this->tabPage2->Controls->Add(this->listBox19);
			this->tabPage2->Controls->Add(this->listBox18);
			this->tabPage2->Controls->Add(this->listBox16);
			this->tabPage2->Controls->Add(this->listBox17);
			this->tabPage2->Controls->Add(this->label140);
			this->tabPage2->Controls->Add(this->label120);
			this->tabPage2->Controls->Add(this->label141);
			this->tabPage2->Controls->Add(this->label142);
			this->tabPage2->Location = System::Drawing::Point(4, 25);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(520, 337);
			this->tabPage2->TabIndex = 0;
			this->tabPage2->Text = L"¬˚Û˜Í‡ ÔÓ ÔÓÂÁ‰‡Ï";
			// 
			// button8
			// 
			this->button8->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(187)), static_cast<System::Int32>(static_cast<System::Byte>(221)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->button8->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->button8->Location = System::Drawing::Point(376, 274);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(121, 45);
			this->button8->TabIndex = 3;
			this->button8->Text = L"Œ·ÌÓ‚ËÚ¸";
			this->button8->UseVisualStyleBackColor = false;
			this->button8->Click += gcnew System::EventHandler(this, &Form1::button8_Click);
			// 
			// label116
			// 
			this->label116->AutoSize = true;
			this->label116->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label116->ForeColor = System::Drawing::Color::Red;
			this->label116->Location = System::Drawing::Point(206, 23);
			this->label116->Name = L"label116";
			this->label116->Size = System::Drawing::Size(87, 22);
			this->label116->TabIndex = 0;
			this->label116->Text = L"¬˚Û˜Í‡";
			// 
			// label118
			// 
			this->label118->AutoSize = true;
			this->label118->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label118->ForeColor = System::Drawing::Color::Red;
			this->label118->Location = System::Drawing::Point(17, 23);
			this->label118->Name = L"label118";
			this->label118->Size = System::Drawing::Size(142, 22);
			this->label118->TabIndex = 0;
			this->label118->Text = L"ÕÓÏÂ ÔÓÂÁ‰‡";
			// 
			// label136
			// 
			this->label136->AutoSize = true;
			this->label136->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label136->Location = System::Drawing::Point(282, 187);
			this->label136->Name = L"label136";
			this->label136->Size = System::Drawing::Size(76, 22);
			this->label136->TabIndex = 0;
			this->label136->Text = L"Û·ÎÂÈ";
			// 
			// label111
			// 
			this->label111->AutoSize = true;
			this->label111->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label111->Location = System::Drawing::Point(282, 147);
			this->label111->Name = L"label111";
			this->label111->Size = System::Drawing::Size(76, 22);
			this->label111->TabIndex = 0;
			this->label111->Text = L"Û·ÎÂÈ";
			// 
			// label121
			// 
			this->label121->AutoSize = true;
			this->label121->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label121->Location = System::Drawing::Point(282, 67);
			this->label121->Name = L"label121";
			this->label121->Size = System::Drawing::Size(76, 22);
			this->label121->TabIndex = 0;
			this->label121->Text = L"Û·ÎÂÈ";
			// 
			// label115
			// 
			this->label115->AutoSize = true;
			this->label115->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label115->Location = System::Drawing::Point(282, 107);
			this->label115->Name = L"label115";
			this->label115->Size = System::Drawing::Size(76, 22);
			this->label115->TabIndex = 0;
			this->label115->Text = L"Û·ÎÂÈ";
			// 
			// label119
			// 
			this->label119->AutoSize = true;
			this->label119->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label119->Location = System::Drawing::Point(282, 274);
			this->label119->Name = L"label119";
			this->label119->Size = System::Drawing::Size(76, 22);
			this->label119->TabIndex = 0;
			this->label119->Text = L"Û·ÎÂÈ";
			// 
			// label139
			// 
			this->label139->AutoSize = true;
			this->label139->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label139->Location = System::Drawing::Point(17, 67);
			this->label139->Name = L"label139";
			this->label139->Size = System::Drawing::Size(87, 22);
			this->label139->TabIndex = 0;
			this->label139->Text = L"1 ÔÓÂÁ‰";
			// 
			// listBox14
			// 
			this->listBox14->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->listBox14->FormattingEnabled = true;
			this->listBox14->ItemHeight = 22;
			this->listBox14->Location = System::Drawing::Point(210, 270);
			this->listBox14->Name = L"listBox14";
			this->listBox14->Size = System::Drawing::Size(50, 26);
			this->listBox14->TabIndex = 2;
			// 
			// listBox19
			// 
			this->listBox19->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->listBox19->FormattingEnabled = true;
			this->listBox19->ItemHeight = 22;
			this->listBox19->Location = System::Drawing::Point(210, 183);
			this->listBox19->Name = L"listBox19";
			this->listBox19->Size = System::Drawing::Size(50, 26);
			this->listBox19->TabIndex = 2;
			// 
			// listBox18
			// 
			this->listBox18->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->listBox18->FormattingEnabled = true;
			this->listBox18->ItemHeight = 22;
			this->listBox18->Location = System::Drawing::Point(210, 143);
			this->listBox18->Name = L"listBox18";
			this->listBox18->Size = System::Drawing::Size(50, 26);
			this->listBox18->TabIndex = 2;
			// 
			// listBox16
			// 
			this->listBox16->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->listBox16->FormattingEnabled = true;
			this->listBox16->ItemHeight = 22;
			this->listBox16->Location = System::Drawing::Point(210, 103);
			this->listBox16->Name = L"listBox16";
			this->listBox16->Size = System::Drawing::Size(50, 26);
			this->listBox16->TabIndex = 2;
			// 
			// listBox17
			// 
			this->listBox17->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->listBox17->FormattingEnabled = true;
			this->listBox17->ItemHeight = 22;
			this->listBox17->Location = System::Drawing::Point(210, 63);
			this->listBox17->Name = L"listBox17";
			this->listBox17->Size = System::Drawing::Size(50, 26);
			this->listBox17->TabIndex = 2;
			// 
			// label140
			// 
			this->label140->AutoSize = true;
			this->label140->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label140->Location = System::Drawing::Point(39, 274);
			this->label140->Name = L"label140";
			this->label140->Size = System::Drawing::Size(153, 22);
			this->label140->TabIndex = 0;
			this->label140->Text = L"»ÚÓ„Ó ‚˚Û˜Í‡";
			// 
			// label120
			// 
			this->label120->AutoSize = true;
			this->label120->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label120->Location = System::Drawing::Point(17, 187);
			this->label120->Name = L"label120";
			this->label120->Size = System::Drawing::Size(87, 22);
			this->label120->TabIndex = 0;
			this->label120->Text = L"4 ÔÓÂÁ‰";
			// 
			// label141
			// 
			this->label141->AutoSize = true;
			this->label141->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label141->Location = System::Drawing::Point(17, 147);
			this->label141->Name = L"label141";
			this->label141->Size = System::Drawing::Size(87, 22);
			this->label141->TabIndex = 0;
			this->label141->Text = L"3 ÔÓÂÁ‰";
			// 
			// label142
			// 
			this->label142->AutoSize = true;
			this->label142->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label142->Location = System::Drawing::Point(17, 107);
			this->label142->Name = L"label142";
			this->label142->Size = System::Drawing::Size(87, 22);
			this->label142->TabIndex = 0;
			this->label142->Text = L"2 ÔÓÂÁ‰";
			// 
			// tabPage13
			// 
			this->tabPage13->BackColor = System::Drawing::Color::LightSteelBlue;
			this->tabPage13->Controls->Add(this->button9);
			this->tabPage13->Controls->Add(this->label137);
			this->tabPage13->Controls->Add(this->label138);
			this->tabPage13->Controls->Add(this->label143);
			this->tabPage13->Controls->Add(this->label144);
			this->tabPage13->Controls->Add(this->label145);
			this->tabPage13->Controls->Add(this->label146);
			this->tabPage13->Controls->Add(this->label147);
			this->tabPage13->Controls->Add(this->label148);
			this->tabPage13->Controls->Add(this->listBox20);
			this->tabPage13->Controls->Add(this->listBox21);
			this->tabPage13->Controls->Add(this->listBox38);
			this->tabPage13->Controls->Add(this->listBox39);
			this->tabPage13->Controls->Add(this->listBox40);
			this->tabPage13->Controls->Add(this->label149);
			this->tabPage13->Controls->Add(this->label150);
			this->tabPage13->Controls->Add(this->label151);
			this->tabPage13->Controls->Add(this->label152);
			this->tabPage13->Location = System::Drawing::Point(4, 25);
			this->tabPage13->Name = L"tabPage13";
			this->tabPage13->Padding = System::Windows::Forms::Padding(3);
			this->tabPage13->Size = System::Drawing::Size(520, 337);
			this->tabPage13->TabIndex = 1;
			this->tabPage13->Text = L"¬˚Û˜Í‡ ÔÓ ÒÚ‡ÌˆËˇÏ";
			// 
			// button9
			// 
			this->button9->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(187)), static_cast<System::Int32>(static_cast<System::Byte>(221)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->button9->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->button9->Location = System::Drawing::Point(376, 274);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(121, 45);
			this->button9->TabIndex = 21;
			this->button9->Text = L"Œ·ÌÓ‚ËÚ¸";
			this->button9->UseVisualStyleBackColor = false;
			this->button9->Click += gcnew System::EventHandler(this, &Form1::button9_Click);
			// 
			// label137
			// 
			this->label137->AutoSize = true;
			this->label137->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label137->ForeColor = System::Drawing::Color::Red;
			this->label137->Location = System::Drawing::Point(206, 23);
			this->label137->Name = L"label137";
			this->label137->Size = System::Drawing::Size(87, 22);
			this->label137->TabIndex = 13;
			this->label137->Text = L"¬˚Û˜Í‡";
			// 
			// label138
			// 
			this->label138->AutoSize = true;
			this->label138->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label138->ForeColor = System::Drawing::Color::Red;
			this->label138->Location = System::Drawing::Point(17, 23);
			this->label138->Name = L"label138";
			this->label138->Size = System::Drawing::Size(87, 22);
			this->label138->TabIndex = 11;
			this->label138->Text = L"—Ú‡ÌˆËˇ";
			// 
			// label143
			// 
			this->label143->AutoSize = true;
			this->label143->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label143->Location = System::Drawing::Point(282, 187);
			this->label143->Name = L"label143";
			this->label143->Size = System::Drawing::Size(76, 22);
			this->label143->TabIndex = 12;
			this->label143->Text = L"Û·ÎÂÈ";
			// 
			// label144
			// 
			this->label144->AutoSize = true;
			this->label144->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label144->Location = System::Drawing::Point(282, 147);
			this->label144->Name = L"label144";
			this->label144->Size = System::Drawing::Size(76, 22);
			this->label144->TabIndex = 15;
			this->label144->Text = L"Û·ÎÂÈ";
			// 
			// label145
			// 
			this->label145->AutoSize = true;
			this->label145->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label145->Location = System::Drawing::Point(282, 67);
			this->label145->Name = L"label145";
			this->label145->Size = System::Drawing::Size(76, 22);
			this->label145->TabIndex = 14;
			this->label145->Text = L"Û·ÎÂÈ";
			// 
			// label146
			// 
			this->label146->AutoSize = true;
			this->label146->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label146->Location = System::Drawing::Point(282, 107);
			this->label146->Name = L"label146";
			this->label146->Size = System::Drawing::Size(76, 22);
			this->label146->TabIndex = 10;
			this->label146->Text = L"Û·ÎÂÈ";
			// 
			// label147
			// 
			this->label147->AutoSize = true;
			this->label147->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label147->Location = System::Drawing::Point(282, 274);
			this->label147->Name = L"label147";
			this->label147->Size = System::Drawing::Size(76, 22);
			this->label147->TabIndex = 6;
			this->label147->Text = L"Û·ÎÂÈ";
			// 
			// label148
			// 
			this->label148->AutoSize = true;
			this->label148->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label148->Location = System::Drawing::Point(17, 67);
			this->label148->Name = L"label148";
			this->label148->Size = System::Drawing::Size(98, 22);
			this->label148->TabIndex = 5;
			this->label148->Text = L" ÓÏ‡Ó‚Ó";
			// 
			// listBox20
			// 
			this->listBox20->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->listBox20->FormattingEnabled = true;
			this->listBox20->ItemHeight = 22;
			this->listBox20->Location = System::Drawing::Point(210, 270);
			this->listBox20->Name = L"listBox20";
			this->listBox20->Size = System::Drawing::Size(50, 26);
			this->listBox20->TabIndex = 18;
			// 
			// listBox21
			// 
			this->listBox21->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->listBox21->FormattingEnabled = true;
			this->listBox21->ItemHeight = 22;
			this->listBox21->Location = System::Drawing::Point(210, 183);
			this->listBox21->Name = L"listBox21";
			this->listBox21->Size = System::Drawing::Size(50, 26);
			this->listBox21->TabIndex = 17;
			// 
			// listBox38
			// 
			this->listBox38->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->listBox38->FormattingEnabled = true;
			this->listBox38->ItemHeight = 22;
			this->listBox38->Location = System::Drawing::Point(210, 143);
			this->listBox38->Name = L"listBox38";
			this->listBox38->Size = System::Drawing::Size(50, 26);
			this->listBox38->TabIndex = 20;
			// 
			// listBox39
			// 
			this->listBox39->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->listBox39->FormattingEnabled = true;
			this->listBox39->ItemHeight = 22;
			this->listBox39->Location = System::Drawing::Point(210, 103);
			this->listBox39->Name = L"listBox39";
			this->listBox39->Size = System::Drawing::Size(50, 26);
			this->listBox39->TabIndex = 19;
			// 
			// listBox40
			// 
			this->listBox40->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->listBox40->FormattingEnabled = true;
			this->listBox40->ItemHeight = 22;
			this->listBox40->Location = System::Drawing::Point(210, 63);
			this->listBox40->Name = L"listBox40";
			this->listBox40->Size = System::Drawing::Size(50, 26);
			this->listBox40->TabIndex = 16;
			// 
			// label149
			// 
			this->label149->AutoSize = true;
			this->label149->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label149->Location = System::Drawing::Point(39, 274);
			this->label149->Name = L"label149";
			this->label149->Size = System::Drawing::Size(153, 22);
			this->label149->TabIndex = 4;
			this->label149->Text = L"»ÚÓ„Ó ‚˚Û˜Í‡";
			// 
			// label150
			// 
			this->label150->AutoSize = true;
			this->label150->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label150->Location = System::Drawing::Point(17, 187);
			this->label150->Name = L"label150";
			this->label150->Size = System::Drawing::Size(98, 22);
			this->label150->TabIndex = 9;
			this->label150->Text = L"¬‡Î¸ÍÓ‚Ó";
			// 
			// label151
			// 
			this->label151->AutoSize = true;
			this->label151->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label151->Location = System::Drawing::Point(17, 147);
			this->label151->Name = L"label151";
			this->label151->Size = System::Drawing::Size(87, 22);
			this->label151->TabIndex = 8;
			this->label151->Text = L"¡‡Ì‡ÛÎ";
			// 
			// label152
			// 
			this->label152->AutoSize = true;
			this->label152->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label152->Location = System::Drawing::Point(17, 107);
			this->label152->Name = L"label152";
			this->label152->Size = System::Drawing::Size(76, 22);
			this->label152->TabIndex = 7;
			this->label152->Text = L"«ËÏÌˇˇ";
			// 
			// tabPage15
			// 
			this->tabPage15->BackColor = System::Drawing::Color::LightSteelBlue;
			this->tabPage15->Controls->Add(this->button29);
			this->tabPage15->Controls->Add(this->label153);
			this->tabPage15->Controls->Add(this->label154);
			this->tabPage15->Controls->Add(this->label176);
			this->tabPage15->Controls->Add(this->label155);
			this->tabPage15->Controls->Add(this->label156);
			this->tabPage15->Controls->Add(this->label166);
			this->tabPage15->Controls->Add(this->label167);
			this->tabPage15->Controls->Add(this->label168);
			this->tabPage15->Controls->Add(this->label169);
			this->tabPage15->Controls->Add(this->listBox41);
			this->tabPage15->Controls->Add(this->listBox46);
			this->tabPage15->Controls->Add(this->listBox42);
			this->tabPage15->Controls->Add(this->listBox43);
			this->tabPage15->Controls->Add(this->listBox44);
			this->tabPage15->Controls->Add(this->listBox45);
			this->tabPage15->Controls->Add(this->label170);
			this->tabPage15->Controls->Add(this->label175);
			this->tabPage15->Controls->Add(this->label172);
			this->tabPage15->Controls->Add(this->label173);
			this->tabPage15->Controls->Add(this->label174);
			this->tabPage15->Controls->Add(this->label180);
			this->tabPage15->Controls->Add(this->label181);
			this->tabPage15->Controls->Add(this->label182);
			this->tabPage15->Controls->Add(this->label183);
			this->tabPage15->Controls->Add(this->label184);
			this->tabPage15->Controls->Add(this->label185);
			this->tabPage15->Controls->Add(this->label186);
			this->tabPage15->Controls->Add(this->label187);
			this->tabPage15->Controls->Add(this->label188);
			this->tabPage15->Controls->Add(this->label189);
			this->tabPage15->Controls->Add(this->label190);
			this->tabPage15->Controls->Add(this->label191);
			this->tabPage15->Controls->Add(this->label192);
			this->tabPage15->Controls->Add(this->label193);
			this->tabPage15->Controls->Add(this->label194);
			this->tabPage15->Location = System::Drawing::Point(4, 25);
			this->tabPage15->Name = L"tabPage15";
			this->tabPage15->Padding = System::Windows::Forms::Padding(3);
			this->tabPage15->Size = System::Drawing::Size(520, 337);
			this->tabPage15->TabIndex = 3;
			this->tabPage15->Text = L"¬˚Û˜Í‡ ÔÓ ÚËÔ‡Ï ‚‡„ÓÌÓ‚";
			// 
			// button29
			// 
			this->button29->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(187)), static_cast<System::Int32>(static_cast<System::Byte>(221)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->button29->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->button29->Location = System::Drawing::Point(376, 274);
			this->button29->Name = L"button29";
			this->button29->Size = System::Drawing::Size(121, 45);
			this->button29->TabIndex = 66;
			this->button29->Text = L"Œ·ÌÓ‚ËÚ¸";
			this->button29->UseVisualStyleBackColor = false;
			this->button29->Click += gcnew System::EventHandler(this, &Form1::button29_Click);
			// 
			// label153
			// 
			this->label153->AutoSize = true;
			this->label153->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label153->ForeColor = System::Drawing::Color::Red;
			this->label153->Location = System::Drawing::Point(206, 23);
			this->label153->Name = L"label153";
			this->label153->Size = System::Drawing::Size(87, 22);
			this->label153->TabIndex = 58;
			this->label153->Text = L"¬˚Û˜Í‡";
			// 
			// label154
			// 
			this->label154->AutoSize = true;
			this->label154->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label154->ForeColor = System::Drawing::Color::Red;
			this->label154->Location = System::Drawing::Point(17, 23);
			this->label154->Name = L"label154";
			this->label154->Size = System::Drawing::Size(120, 22);
			this->label154->TabIndex = 56;
			this->label154->Text = L"“ËÔ ‚‡„ÓÌ‡";
			// 
			// label176
			// 
			this->label176->AutoSize = true;
			this->label176->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label176->Location = System::Drawing::Point(282, 227);
			this->label176->Name = L"label176";
			this->label176->Size = System::Drawing::Size(76, 22);
			this->label176->TabIndex = 57;
			this->label176->Text = L"Û·ÎÂÈ";
			// 
			// label155
			// 
			this->label155->AutoSize = true;
			this->label155->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label155->Location = System::Drawing::Point(282, 187);
			this->label155->Name = L"label155";
			this->label155->Size = System::Drawing::Size(76, 22);
			this->label155->TabIndex = 57;
			this->label155->Text = L"Û·ÎÂÈ";
			// 
			// label156
			// 
			this->label156->AutoSize = true;
			this->label156->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label156->Location = System::Drawing::Point(282, 147);
			this->label156->Name = L"label156";
			this->label156->Size = System::Drawing::Size(76, 22);
			this->label156->TabIndex = 60;
			this->label156->Text = L"Û·ÎÂÈ";
			// 
			// label166
			// 
			this->label166->AutoSize = true;
			this->label166->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label166->Location = System::Drawing::Point(282, 67);
			this->label166->Name = L"label166";
			this->label166->Size = System::Drawing::Size(76, 22);
			this->label166->TabIndex = 59;
			this->label166->Text = L"Û·ÎÂÈ";
			// 
			// label167
			// 
			this->label167->AutoSize = true;
			this->label167->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label167->Location = System::Drawing::Point(282, 107);
			this->label167->Name = L"label167";
			this->label167->Size = System::Drawing::Size(76, 22);
			this->label167->TabIndex = 55;
			this->label167->Text = L"Û·ÎÂÈ";
			// 
			// label168
			// 
			this->label168->AutoSize = true;
			this->label168->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label168->Location = System::Drawing::Point(282, 274);
			this->label168->Name = L"label168";
			this->label168->Size = System::Drawing::Size(76, 22);
			this->label168->TabIndex = 51;
			this->label168->Text = L"Û·ÎÂÈ";
			// 
			// label169
			// 
			this->label169->AutoSize = true;
			this->label169->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label169->Location = System::Drawing::Point(17, 67);
			this->label169->Name = L"label169";
			this->label169->Size = System::Drawing::Size(87, 22);
			this->label169->TabIndex = 50;
			this->label169->Text = L"—Ë‰ˇ˜ËÈ";
			// 
			// listBox41
			// 
			this->listBox41->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->listBox41->FormattingEnabled = true;
			this->listBox41->ItemHeight = 22;
			this->listBox41->Location = System::Drawing::Point(210, 270);
			this->listBox41->Name = L"listBox41";
			this->listBox41->Size = System::Drawing::Size(50, 26);
			this->listBox41->TabIndex = 63;
			// 
			// listBox46
			// 
			this->listBox46->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->listBox46->FormattingEnabled = true;
			this->listBox46->ItemHeight = 22;
			this->listBox46->Location = System::Drawing::Point(210, 223);
			this->listBox46->Name = L"listBox46";
			this->listBox46->Size = System::Drawing::Size(50, 26);
			this->listBox46->TabIndex = 62;
			// 
			// listBox42
			// 
			this->listBox42->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->listBox42->FormattingEnabled = true;
			this->listBox42->ItemHeight = 22;
			this->listBox42->Location = System::Drawing::Point(210, 183);
			this->listBox42->Name = L"listBox42";
			this->listBox42->Size = System::Drawing::Size(50, 26);
			this->listBox42->TabIndex = 62;
			// 
			// listBox43
			// 
			this->listBox43->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->listBox43->FormattingEnabled = true;
			this->listBox43->ItemHeight = 22;
			this->listBox43->Location = System::Drawing::Point(210, 143);
			this->listBox43->Name = L"listBox43";
			this->listBox43->Size = System::Drawing::Size(50, 26);
			this->listBox43->TabIndex = 65;
			// 
			// listBox44
			// 
			this->listBox44->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->listBox44->FormattingEnabled = true;
			this->listBox44->ItemHeight = 22;
			this->listBox44->Location = System::Drawing::Point(210, 103);
			this->listBox44->Name = L"listBox44";
			this->listBox44->Size = System::Drawing::Size(50, 26);
			this->listBox44->TabIndex = 64;
			// 
			// listBox45
			// 
			this->listBox45->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->listBox45->FormattingEnabled = true;
			this->listBox45->ItemHeight = 22;
			this->listBox45->Location = System::Drawing::Point(210, 63);
			this->listBox45->Name = L"listBox45";
			this->listBox45->Size = System::Drawing::Size(50, 26);
			this->listBox45->TabIndex = 61;
			// 
			// label170
			// 
			this->label170->AutoSize = true;
			this->label170->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label170->Location = System::Drawing::Point(39, 274);
			this->label170->Name = L"label170";
			this->label170->Size = System::Drawing::Size(153, 22);
			this->label170->TabIndex = 49;
			this->label170->Text = L"»ÚÓ„Ó ‚˚Û˜Í‡";
			// 
			// label175
			// 
			this->label175->AutoSize = true;
			this->label175->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label175->Location = System::Drawing::Point(17, 227);
			this->label175->Name = L"label175";
			this->label175->Size = System::Drawing::Size(142, 22);
			this->label175->TabIndex = 54;
			this->label175->Text = L" ÛÔÂ+ÚÂÎÂÙÓÌ";
			// 
			// label172
			// 
			this->label172->AutoSize = true;
			this->label172->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label172->Location = System::Drawing::Point(17, 187);
			this->label172->Name = L"label172";
			this->label172->Size = System::Drawing::Size(87, 22);
			this->label172->TabIndex = 54;
			this->label172->Text = L" ÛÔÂ+TV";
			// 
			// label173
			// 
			this->label173->AutoSize = true;
			this->label173->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label173->Location = System::Drawing::Point(17, 147);
			this->label173->Name = L"label173";
			this->label173->Size = System::Drawing::Size(54, 22);
			this->label173->TabIndex = 53;
			this->label173->Text = L" ÛÔÂ";
			// 
			// label174
			// 
			this->label174->AutoSize = true;
			this->label174->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label174->Location = System::Drawing::Point(17, 107);
			this->label174->Name = L"label174";
			this->label174->Size = System::Drawing::Size(98, 22);
			this->label174->TabIndex = 52;
			this->label174->Text = L"œÎ‡ˆÍ‡Ú";
			// 
			// label180
			// 
			this->label180->AutoSize = true;
			this->label180->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label180->Location = System::Drawing::Point(230, 264);
			this->label180->Name = L"label180";
			this->label180->Size = System::Drawing::Size(0, 22);
			this->label180->TabIndex = 48;
			// 
			// label181
			// 
			this->label181->AutoSize = true;
			this->label181->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label181->Location = System::Drawing::Point(17, 264);
			this->label181->Name = L"label181";
			this->label181->Size = System::Drawing::Size(0, 22);
			this->label181->TabIndex = 47;
			// 
			// label182
			// 
			this->label182->AutoSize = true;
			this->label182->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label182->Location = System::Drawing::Point(690, 80);
			this->label182->Name = L"label182";
			this->label182->Size = System::Drawing::Size(0, 22);
			this->label182->TabIndex = 46;
			// 
			// label183
			// 
			this->label183->AutoSize = true;
			this->label183->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label183->Location = System::Drawing::Point(690, 183);
			this->label183->Name = L"label183";
			this->label183->Size = System::Drawing::Size(0, 22);
			this->label183->TabIndex = 45;
			// 
			// label184
			// 
			this->label184->AutoSize = true;
			this->label184->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label184->Location = System::Drawing::Point(690, 128);
			this->label184->Name = L"label184";
			this->label184->Size = System::Drawing::Size(0, 22);
			this->label184->TabIndex = 45;
			// 
			// label185
			// 
			this->label185->AutoSize = true;
			this->label185->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label185->Location = System::Drawing::Point(660, 23);
			this->label185->Name = L"label185";
			this->label185->Size = System::Drawing::Size(0, 22);
			this->label185->TabIndex = 42;
			// 
			// label186
			// 
			this->label186->AutoSize = true;
			this->label186->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label186->Location = System::Drawing::Point(414, 23);
			this->label186->Name = L"label186";
			this->label186->Size = System::Drawing::Size(0, 22);
			this->label186->TabIndex = 43;
			// 
			// label187
			// 
			this->label187->AutoSize = true;
			this->label187->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label187->Location = System::Drawing::Point(206, 23);
			this->label187->Name = L"label187";
			this->label187->Size = System::Drawing::Size(0, 22);
			this->label187->TabIndex = 44;
			// 
			// label188
			// 
			this->label188->AutoSize = true;
			this->label188->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label188->Location = System::Drawing::Point(17, 23);
			this->label188->Name = L"label188";
			this->label188->Size = System::Drawing::Size(0, 22);
			this->label188->TabIndex = 39;
			// 
			// label189
			// 
			this->label189->AutoSize = true;
			this->label189->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label189->Location = System::Drawing::Point(17, 80);
			this->label189->Name = L"label189";
			this->label189->Size = System::Drawing::Size(0, 22);
			this->label189->TabIndex = 38;
			// 
			// label190
			// 
			this->label190->AutoSize = true;
			this->label190->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label190->Location = System::Drawing::Point(17, 183);
			this->label190->Name = L"label190";
			this->label190->Size = System::Drawing::Size(0, 22);
			this->label190->TabIndex = 41;
			// 
			// label191
			// 
			this->label191->AutoSize = true;
			this->label191->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label191->Location = System::Drawing::Point(17, 132);
			this->label191->Name = L"label191";
			this->label191->Size = System::Drawing::Size(0, 22);
			this->label191->TabIndex = 40;
			// 
			// label192
			// 
			this->label192->AutoSize = true;
			this->label192->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label192->Location = System::Drawing::Point(206, 183);
			this->label192->Name = L"label192";
			this->label192->Size = System::Drawing::Size(0, 22);
			this->label192->TabIndex = 9;
			// 
			// label193
			// 
			this->label193->AutoSize = true;
			this->label193->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label193->Location = System::Drawing::Point(206, 132);
			this->label193->Name = L"label193";
			this->label193->Size = System::Drawing::Size(0, 22);
			this->label193->TabIndex = 5;
			// 
			// label194
			// 
			this->label194->AutoSize = true;
			this->label194->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label194->Location = System::Drawing::Point(206, 80);
			this->label194->Name = L"label194";
			this->label194->Size = System::Drawing::Size(0, 22);
			this->label194->TabIndex = 4;
			// 
			// timer2
			// 
			this->timer2->Interval = 200;
			this->timer2->Tick += gcnew System::EventHandler(this, &Form1::timer2_Tick);
			// 
			// imageList1
			// 
			this->imageList1->ImageStream = (cli::safe_cast<System::Windows::Forms::ImageListStreamer^  >(resources->GetObject(L"imageList1.ImageStream")));
			this->imageList1->TransparentColor = System::Drawing::Color::Transparent;
			this->imageList1->Images->SetKeyName(0, L"clock0.jpg");
			this->imageList1->Images->SetKeyName(1, L"clock1.jpg");
			this->imageList1->Images->SetKeyName(2, L"clock2.jpg");
			this->imageList1->Images->SetKeyName(3, L"clock3.jpg");
			this->imageList1->Images->SetKeyName(4, L"clock4.jpg");
			this->imageList1->Images->SetKeyName(5, L"clock5.jpg");
			this->imageList1->Images->SetKeyName(6, L"clock6.jpg");
			this->imageList1->Images->SetKeyName(7, L"clock7.jpg");
			this->imageList1->Images->SetKeyName(8, L"clock8.jpg");
			this->imageList1->Images->SetKeyName(9, L"clock9.jpg");
			this->imageList1->Images->SetKeyName(10, L"clock-.jpg");
			// 
			// tabPage14
			// 
			this->tabPage14->BackColor = System::Drawing::Color::LightSteelBlue;
			this->tabPage14->Location = System::Drawing::Point(4, 25);
			this->tabPage14->Name = L"tabPage14";
			this->tabPage14->Padding = System::Windows::Forms::Padding(3);
			this->tabPage14->Size = System::Drawing::Size(1008, 620);
			this->tabPage14->TabIndex = 9;
			this->tabPage14->Text = L"tabPage14";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(187)), static_cast<System::Int32>(static_cast<System::Byte>(221)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->ClientSize = System::Drawing::Size(969, 652);
			this->Controls->Add(this->tabImitation);
			this->Controls->Add(this->menuStrip1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->MainMenuStrip = this->menuStrip1;
			this->MaximumSize = System::Drawing::Size(1026, 712);
			this->MinimumSize = System::Drawing::Size(617, 517);
			this->Name = L"Form1";
			this->SizeGripStyle = System::Windows::Forms::SizeGripStyle::Hide;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"∆ÂÎÂÁÌ‡ˇ ‰ÓÓ„‡ 2014";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Activated += gcnew System::EventHandler(this, &Form1::Form1_Activated);
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->tabPage3->ResumeLayout(false);
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox8))->EndInit();
			this->panel4->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox7))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox10))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox11))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox12))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox13))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox14))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox15))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox16))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox17))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox18))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox19))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox20))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox21))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox22))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox23))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox24))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox25))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox26))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox27))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox28))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox29))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox30))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox31))->EndInit();
			this->panel8->ResumeLayout(false);
			this->panel8->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox32))->EndInit();
			this->panel9->ResumeLayout(false);
			this->panel9->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox33))->EndInit();
			this->panel10->ResumeLayout(false);
			this->panel10->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox34))->EndInit();
			this->panel11->ResumeLayout(false);
			this->panel11->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox35))->EndInit();
			this->panel12->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox36))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox37))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox38))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox39))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox40))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox41))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox42))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox43))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox44))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox45))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox46))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox47))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox48))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox49))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox50))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox51))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox52))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox53))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox54))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox55))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox56))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox57))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox58))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox59))->EndInit();
			this->panel13->ResumeLayout(false);
			this->panel13->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox60))->EndInit();
			this->panel14->ResumeLayout(false);
			this->panel14->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox61))->EndInit();
			this->panel15->ResumeLayout(false);
			this->panel15->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox62))->EndInit();
			this->panel16->ResumeLayout(false);
			this->panel16->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox63))->EndInit();
			this->panel17->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox64))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox65))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox66))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox67))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox68))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox69))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox70))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox71))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox72))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox73))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox74))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox75))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox76))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox77))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox78))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox79))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox80))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox81))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox82))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox83))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox84))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox85))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox86))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox87))->EndInit();
			this->panel18->ResumeLayout(false);
			this->panel18->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox88))->EndInit();
			this->panel19->ResumeLayout(false);
			this->panel19->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox89))->EndInit();
			this->panel20->ResumeLayout(false);
			this->panel20->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox90))->EndInit();
			this->Imitation->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->panel22->ResumeLayout(false);
			this->panel22->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox92))->EndInit();
			this->panel23->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->ten1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->sec0))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->ten_hour))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->hour2))->EndInit();
			this->panel24->ResumeLayout(false);
			this->panel24->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox117))->EndInit();
			this->panel25->ResumeLayout(false);
			this->panel25->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox118))->EndInit();
			this->panel21->ResumeLayout(false);
			this->panel21->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox91))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->hour4))->EndInit();
			this->tabImitation->ResumeLayout(false);
			this->tabPage8->ResumeLayout(false);
			this->tabPage8->PerformLayout();
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			this->tabControl1->ResumeLayout(false);
			this->tabPage9->ResumeLayout(false);
			this->tabPage9->PerformLayout();
			this->tabPage10->ResumeLayout(false);
			this->tabPage10->PerformLayout();
			this->tabPage11->ResumeLayout(false);
			this->tabPage11->PerformLayout();
			this->tabPage12->ResumeLayout(false);
			this->tabPage12->PerformLayout();
			this->tabPage6->ResumeLayout(false);
			this->tabPage6->PerformLayout();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->tabPage5->ResumeLayout(false);
			this->tabPage5->PerformLayout();
			this->panel5->ResumeLayout(false);
			this->panel5->PerformLayout();
			this->tabPage7->ResumeLayout(false);
			this->tabPage7->PerformLayout();
			this->tabControl2->ResumeLayout(false);
			this->tabPage2->ResumeLayout(false);
			this->tabPage2->PerformLayout();
			this->tabPage13->ResumeLayout(false);
			this->tabPage13->PerformLayout();
			this->tabPage15->ResumeLayout(false);
			this->tabPage15->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
private: int i,k,m,n,schet,f,f1,i1,i2,i3,i4,stantion,stantion2;
		 int price,price1,price2,price3,price4,price5,pr1,pr2,pr3,pr4,pri1,pri2,pri3,pri4;
		 int mar1,mar2,mar3,mar4,mar5,mar6,mar7,mar8,mar9,mar10,mar11,mar12;


 Slu *WagonSlu12, *WagonSlu22, *WagonSlu33;
 Pas *WagonPas11, *WagonPas13, *WagonPas21, *WagonPas23, *WagonPas31, *WagonPas32, *WagonPas41, *WagonPas42, *WagonPas43;

private: System::Void Form1_Activated(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void numericUpDown1_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
		 }

private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
			 tabPage14->Text="Œ ÔÓ„‡ÏÏÂ";
			 i=0;
			 k=0;
			 m=0;
			 n=0;
			 i1=0;
			 i2=0;
			 i3=0;
			 i4=0;
			 mar1=0;mar2=0;mar3=0;
			 mar4=0;mar5=0;mar6=0;
			 mar7=0;mar8=0;mar9=0;
			 mar10=0;mar11=0;mar12=0;
			 price=0; // ˆÂÌ‡ ·ËÎÂÚ‡
			 price1=0;
			 price2=0;
			 price3=0;
			 price4=0;
			 price5=0;
			 pr1=0;
			 pr2=0;
			 pr3=0;
			 pr4=0;
			 pri1=0;
			 pri2=0;
			 pri3=0;
			 pri4=0;
			 stantion=0;
			 f=1;
			 f1=1;
			 schet=0;
			 sec0->Visible=true;
			 ten1->Visible=true;
			 button32->Text="œÛÒÍ";
			 ten1->Image = imageList1->Images[ 0 ];
			 sec0->Image = imageList1->Images[ 0 ];
			 hour2->Image = imageList1->Images[ 0 ];
			 ten_hour->Image = imageList1->Images[ 0 ];
			  // ÔÂ‚˚È ÔÓÂÁ‰
 
	 WagonPas11=new Pas();  WagonPas11->settippas(4);
	 WagonSlu12=new Slu();  WagonSlu12->settipslu(2);
     WagonPas13=new Pas();  WagonPas13->settippas(3);
	 	 	
     // ‚ÚÓÓÈ ÔÓÂÁ‰
	 WagonPas21=new Pas();  WagonPas21->settippas(3);
	 WagonSlu22=new Slu();  WagonSlu22->settipslu(2);
	 WagonPas23=new Pas();  WagonPas23->settippas(1);
	 
	 // ÚÂÚËÈ ÔÓÂÁ‰
	 WagonPas31=new Pas();  WagonPas31->settippas(2);
	 WagonPas32=new Pas();  WagonPas32->settippas(2);
	 WagonSlu33=new Slu();  WagonSlu33->settipslu(1);

	 // ˜ÂÚ‚ÂÚ˚È ÔÓÂÁ‰
	 WagonPas41=new Pas();  WagonPas41->settippas(3);
	 WagonPas42=new Pas();  WagonPas42->settippas(4);
	 WagonPas43=new Pas();  WagonPas43->settippas(5);

	 WagonPas11->setseats(4);
	 WagonPas13->setseats(36);
	 WagonPas21->setseats(36);
	 WagonPas31->setseats(36);
	 WagonPas31->setseats(36);
	 WagonPas32->setseats(36);
	 WagonPas41->setseats(36);
	 WagonPas42->setseats(4);
	 WagonPas43->setseats(36);

		 }
	 	 
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
			n++; // Ò˜ÂÚ˜ËÍ ÒÂÍÛÌ‰
			i++;
			if ((n==30)||(n==60))
			{
				WagonPas11->setseats(4);
				WagonPas13->setseats(36);
				WagonPas21->setseats(36);
				WagonPas31->setseats(36);
				WagonPas31->setseats(36);
				WagonPas32->setseats(36);
				WagonPas41->setseats(36);
				WagonPas42->setseats(4);
				WagonPas43->setseats(36);
			}
			if (n<=80)
			{
				if (i>9) {k++; i=0;}
				if (k>5) {k=0; m++;}
				if (i==0)
					{sec0->Image = imageList1->Images[ 0 ];}
				if (i==1)
					{sec0->Image = imageList1->Images[ 1 ];}
				if (i==2)
					{sec0->Image = imageList1->Images[ 2 ];}
				if (i==3)
					{sec0->Image = imageList1->Images[ 3 ];}
				if (i==4)
					{sec0->Image = imageList1->Images[ 4 ];}
				if (i==5)
					{sec0->Image = imageList1->Images[ 5 ];}
				if (i==6)
					{sec0->Image = imageList1->Images[ 6 ];}
				if (i==7)
					{sec0->Image = imageList1->Images[ 7 ];}
				if (i==8)
					{sec0->Image = imageList1->Images[ 8 ];}
				if (i==9)
					{sec0->Image = imageList1->Images[ 9 ];}

				if (k==0)
					{ten1->Image = imageList1->Images[ 0 ];}
				if (k==1)
					{ten1->Image = imageList1->Images[ 1 ];}
				if (k==2)
					{ten1->Image = imageList1->Images[ 2 ];}
				if (k==3)
					{ten1->Image = imageList1->Images[ 3 ];}
				if (k==4)
					{ten1->Image = imageList1->Images[ 4 ];}
				if (k==5)
					{ten1->Image = imageList1->Images[ 5 ];}
				if (m<=9)
				{
					this->hour2->Image = imageList1->Images[ m ];
					//if (hour)
						//this->ten_hour->Image=imageList1->Images[ 1 ];
					//else 
						//this->ten_hour->Image=imageList1->Images[ 0 ];
				}
				else
				{
					m=0;
					this->hour2->Image = imageList1->Images[ m ];
					//if (hour)
						//this->ten_hour->Image=imageList1->Images[ 1 ];
					//else
						//this->ten_hour->Image=imageList1->Images[ 0 ];
				}


			}
          						
		 }

 private: System::Void button32_Click(System::Object^  sender, System::EventArgs^  e) {
				 if (schet) {
				 button32->Text="œÛÒÍ";
				 timer1->Enabled=false;
				 timer2->Enabled=false;
				 buttoncom->Enabled=true;
				 buttonzim->Enabled=true;
				 buttonbar->Enabled=true;
				 buttonval->Enabled=true;
				 surname->Text="";
			     comboBox4->Text="";
				 label30->Text="     ";
				 label99->Text="     ";
				 label24->Text="     ";
				 comboBox2->Text="";
				 checkBox1->Checked=false;
				 checkBox2->Checked=false;
				 checkBox3->Checked=false;
				 checkBox4->Checked=false;
				 schet=0;
			 }
			 else {
				 button32->Text="—ÚÓÔ";
				 timer1->Enabled=true;
				 timer2->Enabled=true;
				 panel2->Enabled=false;
				 buttoncom->Enabled=false;
				 buttonzim->Enabled=false;
				 buttonbar->Enabled=false;
				 buttonval->Enabled=false;
				 schet=1;
			 }
		 		 
		 }

		// ÓÔÂ‰ÂÎÂÌËÂ ÚÂÍÛ˘ÂÈ ÒÚ‡ÌˆËË 
private: System::Void buttoncom_Click(System::Object^  sender, System::EventArgs^  e) {
			 stantion=1;
			 f1=1;
			 buttonzim->Enabled=false;
			 buttonbar->Enabled=false;
			 buttonval->Enabled=false;
			 panel2->Enabled=true;		
		}
private: System::Void buttonzim_Click(System::Object^  sender, System::EventArgs^  e) { 
			 stantion=2;
			 f1=1;
			 buttoncom->Enabled=false;
			 buttonbar->Enabled=false;
			 buttonval->Enabled=false;
			 panel2->Enabled=true;	
		 }
private: System::Void buttonbar_Click(System::Object^  sender, System::EventArgs^  e) {
			 stantion=3;
			 f1=1;
			 buttoncom->Enabled=false;
			 buttonzim->Enabled=false;
			 buttonval->Enabled=false;
			 panel2->Enabled=true;	
		 }
private: System::Void buttonval_Click(System::Object^  sender, System::EventArgs^  e) {
			 stantion=4;
			 f1=1;
			 buttoncom->Enabled=false;
			 buttonzim->Enabled=false;
			 buttonbar->Enabled=false;
			 panel2->Enabled=true;	
		 }

private: System::Void button30_Click(System::Object^  sender, System::EventArgs^  e) {
			 int reason1, reason2, reason3;
			 reason1=0; // ÔË˜ËÌ‡ ‚ ÓÚÒÛÚÒ‚ËË ‚‡„ÓÌ‡-ÂÒÚÓ‡Ì‡
			 reason2=0; // ÔË˜ËÌ‡ ‚ ÓÚÒÛÚÒ‚ËË ·ËÎÂÚÓ‚
			 reason3=0; // ÔË˜ËÌ‡ ‚ ÓÚÒÛÚÒ‚ËË Ú‡ÍÓ„Ó ‚‡„ÓÌ‡ ‚ ÔÓÂÁ‰Â
             if ((surname->Text=="")|| // ÔÓ‚ÂÍ‡ Ì‡ Ô‡‚ËÎ¸ÌÓÒÚ¸ Á‡ÔÓÎÌÂÌËˇ
				 ((comboBox4->Text!=" ÓÏ‡Ó‚Ó")&&(comboBox4->Text!="«ËÏÌˇˇ")&&
				 (comboBox4->Text!="¬‡Î¸ÍÓ‚Ó")&&(comboBox4->Text!="¡‡Ì‡ÛÎ"))||
				 (label30->Text=="Error")||((comboBox2->Text!=" ÛÔÂ")&&(comboBox2->Text!="—Ë‰ˇ˜ËÈ")&&
				 (comboBox2->Text!="œÎ‡ˆÍ‡Ú"))) MessageBox::Show("ÕÂÍÓÂÍÚÌÓÂ Á‡ÔÓÎÌÂÌËÂ ÔÓÎÂÈ");
			 else	 {				
		 int tipvag=0;
		 if (((label30->Text=="3")||(label30->Text=="4"))&&(checkBox1->Checked==true))
			 reason1=1;
		 else
			{   
			 if ((comboBox2->Text=="—Ë‰ˇ˜ËÈ")&&(label30->Text=="2")) tipvag=1; else reason3=1;
			 if ((comboBox2->Text=="œÎ‡ˆÍ‡Ú")&&(label30->Text=="3")) tipvag=2; else reason3=1;
			 if ((comboBox2->Text==" ÛÔÂ")&&(label30->Text!="3")&&(checkBox3->Checked==false)&&(checkBox4->Checked==false))tipvag=3; else reason3=1;
			 if ((comboBox2->Text==" ÛÔÂ")&&((label30->Text=="1")||(label30->Text=="4"))&&(checkBox3->Checked==true)&&(checkBox4->Checked==false)) tipvag=4; else reason3=1;
			 if ((comboBox2->Text==" ÛÔÂ")&&(label30->Text=="4")&&(checkBox3->Checked==false)&&(checkBox4->Checked==true)) tipvag=5; else reason3=1;
			 if (label30->Text=="1")
			 {
				 if ((WagonPas11->gettippas()==tipvag)&&(WagonPas11->getseats()>0))
				 {
					 WagonPas11->setseats(WagonPas11->getseats()-1); 
					 f1=0;
				 }
				 else if (WagonPas11->getseats()<=0) reason2=1;

				 if ((WagonPas13->gettippas()==tipvag)&&(WagonPas13->getseats()>0))
				 {
					 WagonPas13->setseats(WagonPas13->getseats()-1); 
					 f1=0;
				 }
				 else if (WagonPas13->getseats()<=0) reason2=1;
			 }
		 		
			 if (label30->Text=="2")
			 {
				 if ((WagonPas21->gettippas()==tipvag)&&(WagonPas21->getseats()>0))
				 {
					 WagonPas21->setseats(WagonPas21->getseats()-1); 
					 f1=0;
				 }
				 else if (WagonPas21->getseats()<=0) reason2=1;

				 if ((WagonPas23->gettippas()==tipvag)&&(WagonPas23->getseats()>0))
				 {
					 WagonPas23->setseats(WagonPas23->getseats()-1); 
					 f1=0;}
				 else if (WagonPas23->getseats()<=0) reason2=1;
			 }
				 
			 if (label30->Text=="3")
			 {
				 if ((WagonPas31->gettippas()==tipvag)&&(WagonPas31->getseats()>0))
				 {
					 WagonPas31->setseats(WagonPas31->getseats()-1); 
					 f1=0;
				 }
				 else if (WagonPas31->getseats()<=0) reason2=1;

			 else
				 if ((WagonPas32->gettippas()==tipvag)&&(WagonPas32->getseats()>0))
				 {
					 WagonPas32->setseats(WagonPas32->getseats()-1);
					 f1=0;
				 }
				  else if (WagonPas32->getseats()<=0) reason2=1;
			 }
				
			 if (label30->Text=="4")
			 {
				 if ((WagonPas41->gettippas()==tipvag)&&(WagonPas41->getseats()>0))
				 {
					 WagonPas41->setseats(WagonPas41->getseats()-1); 
					 f1=0;
				 }
				 else if (WagonPas41->getseats()<=0) reason2=1;

				 if ((WagonPas42->gettippas()==tipvag)&&(WagonPas42->getseats()>0))
				 {
					 WagonPas42->setseats(WagonPas42->getseats()-1);
				     f1=0;
				 }
				  else if (WagonPas42->getseats()<=0) reason2=1;

				 if ((WagonPas43->gettippas()==tipvag)&&(WagonPas43->getseats()>0))
				 {
					 WagonPas43->setseats(WagonPas43->getseats()-1);
					 f1=0;
				 }
				 else if (WagonPas43->getseats()<=0) reason2=1;

			 }
		 }
			 if (f1) 
			 {
				 if (reason1) MessageBox::Show("¡ËÎÂÚ‡ ÌÂÚ, ÔË˜ËÌ‡ ‚ ÓÚÒÛÚÒÚ‚ËË ‚‡„ÓÌ‡ - ÂÒÚÓ‡Ì‡");
				 if (reason2) MessageBox::Show("¡ËÎÂÚ‡ ÌÂÚ, ÔË˜ËÌ‡ ‚ ÓÚÒÚÛÚÒÚ‚ËË Ò‚Ó·Ó‰Ì˚ı ÏÂÒÚ");
				 if (reason3) MessageBox::Show("¡ËÎÂÚ‡ ÌÂÚ, ÔË˜ËÌ‡ ‚ ÓÚÒÛÚÒÚ‚ËË Á‡ÔÓ¯ÂÌÓ„Ó ‚‡„ÓÌ‡ ‚ ÔÓÂÁ‰Â");
			 }
			 else
			 {		// ÔÓ‰Ò˜ÂÚ ˆÂÌ˚	
				 int p=0; int s=0;
				 if (checkBox2->Checked==true) p=p+20; // ÔÓ ‚‡„ÓÌ‡Ï
				 if (tipvag==1) {price1=price1+100+p; price=price+price1; s=s+100+p;} else
					 if (tipvag==2) {price2=price2+200+p; price=price+price1; s=s+200+p;} else
						 if (tipvag==3) {price3=price3+300+p; price=price+price1; s=s+300+p;} else
							 if (tipvag==4) {price4=price4+400+p; price=price+price1; s=s+400+p;} else
								 if (tipvag==5) {price5=price5+350+p; price=price+price1; s=s+350+p;};
				 if (stantion==1) pr1=pr1+s; // ÔÓ ÒÚ‡ÌˆËˇÏ
					 if (stantion==2) pr2=pr2+s;
						 if (stantion==3) pr3=pr3+s;
							 if (stantion==4) pr4=pr4+s;
				 if (label30->Text=="1") pri1=pri1+s; // ÔÓ ÔÓÂÁ‰‡Ï
					 if (label30->Text=="2") pri2=pri2+s;
						 if (label30->Text=="3") pri3=pri3+s;
							 if (label30->Text=="4") pri4=pri4+s; 
							 MessageBox::Show("¡ËÎÂÚ ÔÓ ‚‡¯ÂÏÛ Á‡ÔÓÒÛ ÂÒÚ¸");
				 	 if ((stantion==1)&&(stantion2==2)) mar1++;
					 if ((stantion==1)&&(stantion2==3)) mar2++;
					 if ((stantion==1)&&(stantion2==4)) mar3++;
					 if ((stantion==2)&&(stantion2==1)) mar4++;
					 if ((stantion==2)&&(stantion2==3)) mar5++;
					 if ((stantion==2)&&(stantion2==4)) mar6++;
					 if ((stantion==3)&&(stantion2==1)) mar7++;
					 if ((stantion==3)&&(stantion2==2)) mar8++;
					 if ((stantion==3)&&(stantion2==4)) mar9++;
					 if ((stantion==4)&&(stantion2==1)) mar10++;
					 if ((stantion==4)&&(stantion2==2)) mar11++;
					 if ((stantion==4)&&(stantion2==3)) mar12++;
			 }
			 surname->Text="";
			 comboBox4->Text="";
			 label30->Text="     ";
			 label99->Text="     ";
			 label24->Text="     ";
			 buttoncom->Enabled=true;
			 buttonzim->Enabled=true;
			 buttonbar->Enabled=true;
			 buttonval->Enabled=true;
			 comboBox2->Text="";
			 checkBox1->Checked=false;
			 checkBox2->Checked=false;
			 checkBox3->Checked=false;
			 checkBox4->Checked=false;
			 panel2->Enabled=false;
			 }
 
		 }

private: System::Void comboBox4_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 // ‰Îˇ ÔÂ‚ÓÈ ÒÚ‡ÌˆËË
			 	 if (comboBox4->Text==" ÓÏ‡Ó‚Ó") stantion2=1;
				 if (comboBox4->Text=="«ËÏÌˇˇ") stantion2=2;
				 if (comboBox4->Text=="¬‡Î¸ÍÓ‚Ó") stantion2=4;
				 if (comboBox4->Text=="¡‡Ì‡ÛÎ") stantion2=3;
			 if (stantion==1)
			 {
				 if (comboBox4->Text==" ÓÏ‡Ó‚Ó") 
			 {   
				 label99->Text="¬˚ Ì‡ıÓ‰ËÚÂÒ¸ ‚ ÔÛÌÍÚÂ Ì‡ÁÌ‡˜ÂÌËˇ";
				 label30->Text="Error";
				 label24->Text="Error";
			 }
			 if ((comboBox4->Text==comnaz1->Text)&&(n==0))
			 {   
				 label99->Text="¬ÂÏˇ Ì‡È‰ÂÌÓ:";
				 label30->Text=comnum1->Text;
				 label24->Text=com1->Text;
			 }
             if ((comboBox4->Text==comnaz1->Text)&&(n>0))
			 {   label99->Text="¬˚ ÓÔÓÁ‰‡ÎË";
				 label30->Text="Error";
				 label24->Text="Error";
			 }

			 if ((comboBox4->Text==comnaz2->Text)&&(n<30)) 
		     {
				 label99->Text="¬˚ ÔË¯ÎË ‡ÌÓ";
				 label30->Text="Error";
				 label24->Text="Error";
			 }

			 if ((comboBox4->Text==comnaz2->Text)&&(n>=30)&&(n<60)) 
		     {
				 label99->Text="¬ÂÏˇ Ì‡È‰ÂÌÓ:";
				 label30->Text=comnum2->Text;
				 label24->Text=com2->Text;
			 }
			 
			 if ((comboBox4->Text==comnaz2->Text)&&(n>60)) 
		     {
				 label99->Text="¬˚ ÓÔÓÁ‰‡ÎË";
				 label30->Text="Error";
				 label24->Text="Error";
			 }

			 if ((comboBox4->Text==comnaz3->Text)&&(n<30)) 
		     {
				 label99->Text="¬˚ ÔË¯ÎË ‡ÌÓ";
				 label30->Text="Error";
				 label24->Text="Error";
			 }

			 if ((comboBox4->Text==comnaz3->Text)&&(n>=30)&&(n<60)) 
		     {
				 label99->Text="¬ÂÏˇ Ì‡È‰ÂÌÓ:";
				 label30->Text=comnum3->Text;
				 label24->Text=com3->Text;
			 }
			 
			 if ((comboBox4->Text==comnaz3->Text)&&(n>60)) 
		     {
				 label99->Text="¬˚ ÓÔÓÁ‰‡ÎË";
				 label30->Text="Error";
				 label24->Text="Error";
			 }
			 }
	//==================================================================
			 if (stantion==2)
			 {
				 if (comboBox4->Text=="«ËÏÌˇˇ") 
			 {   
				 label99->Text="¬˚ Ì‡ıÓ‰ËÚÂÒ¸ ‚ ÔÛÌÍÚÂ Ì‡ÁÌ‡˜ÂÌËˇ";
				 label30->Text="Error";
				 label24->Text="Error";
			 }
			 if ((comboBox4->Text==zimnaz1->Text)&&(n==0))
			 {   
				 label99->Text="¬ÂÏˇ Ì‡È‰ÂÌÓ:";
				 label30->Text=zimnum1->Text;
				 label24->Text=zim1->Text;
			 }
             if ((comboBox4->Text==zimnaz1->Text)&&(n>0))
			 {   label99->Text="¬˚ ÓÔÓÁ‰‡ÎË";
				 label30->Text="Error";
				 label24->Text="Error";
			 }
			 if ((comboBox4->Text==zimnaz2->Text)&&(n==0)) 
		     {
				 label99->Text="¬˚ ÔË¯ÎË ‡ÌÓ";
				 label30->Text="Error";
				 label24->Text="Error";
			 }
			 if ((comboBox4->Text==zimnaz2->Text)&&(n>0)&&(n<30)) 
		     {
				 label99->Text="¬ÂÏˇ Ì‡È‰ÂÌÓ:";
				 label30->Text=zimnum2->Text;
				 label24->Text=zim2->Text;
			 }			 
			 if ((comboBox4->Text==zimnaz2->Text)&&(n>30)) 
		     {
				 label99->Text="¬˚ ÓÔÓÁ‰‡ÎË";
				 label30->Text="Error";
				 label24->Text="Error";
			 }
			 if ((comboBox4->Text==zimnaz3->Text)&&(n==0)) 
		     {
				 label99->Text="¬˚ ÔË¯ÎË ‡ÌÓ";
				 label30->Text="Error";
				 label24->Text="Error";
			 }

			 if ((comboBox4->Text==zimnaz3->Text)&&(n>0)&&(n<30)) 
		     {
				 label99->Text="¬ÂÏˇ Ì‡È‰ÂÌÓ:";
				 label30->Text=zimnum3->Text;
				 label24->Text=zim3->Text;
			 }
			 
			 if ((comboBox4->Text==zimnaz3->Text)&&(n>30)) 
		     {
				 label99->Text="¬˚ ÓÔÓÁ‰‡ÎË";
				 label30->Text="Error";
				 label24->Text="Error";
			 }
			 }
	 // ================================================
	 if (stantion==3)
			 {
				 if (comboBox4->Text=="¡‡Ì‡ÛÎ") 
			 {   
				 label99->Text="¬˚ ‚ ÔÛÌÍÚÂ Ì‡ÁÌ‡˜ÂÌËˇ";
				 label30->Text="Error";
				 label24->Text="Error";
			 }
			 if ((comboBox4->Text==barnaz1->Text)&&(n==0))
			 {   
				 label99->Text="¬ÂÏˇ Ì‡È‰ÂÌÓ:";
				 label30->Text=barnum1->Text;
				 label24->Text=bar1->Text;
			 }
             if ((comboBox4->Text==barnaz1->Text)&&(n>0))
			 {   label99->Text="¬˚ ÓÔÓÁ‰‡ÎË";
				 label30->Text="Error";
				 label24->Text="Error";
			 }
			 if ((comboBox4->Text==barnaz2->Text)&&(n==0)) 
		     {
				 label99->Text="¬˚ ÔË¯ÎË ‡ÌÓ";
				 label30->Text="Error";
				 label24->Text="Error";
			 }
			 if ((comboBox4->Text==barnaz2->Text)&&(n>0)&&(n<30)) 
		     {
				 label99->Text="¬ÂÏˇ Ì‡È‰ÂÌÓ:";
				 label30->Text=barnum2->Text;
				 label24->Text=bar2->Text;
			 }			 
			 if ((comboBox4->Text==barnaz2->Text)&&(n>30)) 
		     {
				 label99->Text="¬˚ ÓÔÓÁ‰‡ÎË";
				 label30->Text="Error";
				 label24->Text="Error";
			 }
			 if ((comboBox4->Text==barnaz3->Text)&&(n==0)) 
		     {
				 label99->Text="¬˚ ÔË¯ÎË ‡ÌÓ";
				 label30->Text="Error";
				 label24->Text="Error";
			 }
			 if ((comboBox4->Text==barnaz3->Text)&&(n>0)&&(n<30)) 
		     {
				 label99->Text="¬ÂÏˇ Ì‡È‰ÂÌÓ:";
				 label30->Text=barnum3->Text;
				 label24->Text=bar3->Text;
			 }
			 
			 if ((comboBox4->Text==barnaz3->Text)&&(n>30)) 
		     {
				 label99->Text="¬˚ ÓÔÓÁ‰‡ÎË";
				 label30->Text="Error";
				 label24->Text="Error";
			 }
			 }
	 // ============================================
	  if (stantion==4)
			 {
				 if (comboBox4->Text=="¬‡Î¸ÍÓ‚Ó") 
			 {   
				 label99->Text="¬˚ Ì‡ıÓ‰ËÚÂÒ¸ ‚ ÔÛÌÍÚÂ Ì‡ÁÌ‡˜ÂÌËˇ";
				 label30->Text="Error";
				 label24->Text="Error";
			 }
			 if ((comboBox4->Text==valnaz1->Text)&&(n==0))
			 {   
				 label99->Text="¬ÂÏˇ Ì‡È‰ÂÌÓ:";
				 label30->Text=valnum1->Text;
				 label24->Text=val1->Text;
			 }
             if ((comboBox4->Text==valnaz1->Text)&&(n>0))
			 {   label99->Text="¬˚ ÓÔÓÁ‰‡ÎË";
				 label30->Text="Error";
				 label24->Text="Error";
			 }
			 if ((comboBox4->Text==valnaz2->Text)&&(n<30)) 
		     {
				 label99->Text="¬˚ ÔË¯ÎË ‡ÌÓ";
				 label30->Text="Error";
				 label24->Text="Error";
			 }
			 if ((comboBox4->Text==valnaz2->Text)&&(n>=30)&&(n<60)) 
		     {
				 label99->Text="¬ÂÏˇ Ì‡È‰ÂÌÓ:";
				 label30->Text=valnum2->Text;
				 label24->Text=val2->Text;
			 }
			 if ((comboBox4->Text==valnaz2->Text)&&(n>60)) 
		     {
				 label99->Text="¬˚ ÓÔÓÁ‰‡ÎË";
				 label30->Text="Error";
				 label24->Text="Error";
			 }
			 if ((comboBox4->Text==valnaz3->Text)&&(n<30)) 
		     {
				 label99->Text="¬˚ ÔË¯ÎË ‡ÌÓ";
				 label30->Text="Error";
				 label24->Text="Error";
			 }
			 if ((comboBox4->Text==valnaz3->Text)&&(n>=30)&&(n<60)) 
		     {
				 label99->Text="¬ÂÏˇ Ì‡È‰ÂÌÓ:";
				 label30->Text=valnum3->Text;
				 label24->Text=val3->Text;
			 }			 
			 if ((comboBox4->Text==valnaz3->Text)&&(n>60)) 
		     {
				 label99->Text="¬˚ ÓÔÓÁ‰‡ÎË";
				 label30->Text="Error";
				 label24->Text="Error";
			 }
			 }
		 }
		 
		 
private: System::Void new1_Click(System::Object^  sender, System::EventArgs^  e) {
listBox1->Items->Clear();
listBox1->Items->Add(WagonPas11->getseats());
listBox3->Items->Clear();
listBox3->Items->Add(WagonPas13->getseats());
listBox28->Items->Clear();
listBox28->Items->Add(40-WagonPas11->getseats()-WagonPas13->getseats());
		 }

private: System::Void button2_Click_1(System::Object^  sender, System::EventArgs^  e) {
listBox7->Items->Clear();
listBox7->Items->Add(WagonPas21->getseats());
listBox5->Items->Clear();
listBox5->Items->Add(WagonPas23->getseats());
listBox29->Items->Clear();
listBox29->Items->Add(72-WagonPas21->getseats()-WagonPas23->getseats());
		 }
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
listBox10->Items->Clear();
listBox10->Items->Add(WagonPas31->getseats());
listBox9->Items->Clear();
listBox9->Items->Add(WagonPas32->getseats());
listBox30->Items->Clear();
listBox30->Items->Add(72-WagonPas31->getseats()-WagonPas32->getseats());
		 }
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
listBox13->Items->Clear();
listBox13->Items->Add(WagonPas41->getseats());
listBox12->Items->Clear();
listBox12->Items->Add(WagonPas42->getseats());
listBox11->Items->Clear();
listBox11->Items->Add(WagonPas43->getseats());
listBox31->Items->Clear();
listBox31->Items->Add(76-WagonPas41->getseats()-WagonPas42->getseats()-WagonPas43->getseats());
		 }


private: System::Void comboBox2_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if (comboBox2->Text==" ÛÔÂ") 
			 {
				 checkBox2->Enabled=true;
				 checkBox3->Enabled=true;
				 checkBox4->Enabled=true;
			 }
			 else 
			 {
				 checkBox2->Enabled=false;
				 checkBox3->Enabled=false;
				 checkBox4->Enabled=false;
			 }
		 }
private: System::Void timer2_Tick(System::Object^  sender, System::EventArgs^  e) {
 
if ((n<20)&&(n>=0))
{i1++;
pictureBox1->SetBounds(40+4*i1, 140, 320, 48);
pictureBox2->SetBounds(440-i1*4, 140+i1*3, 320, 48);
pictureBox3->SetBounds(40+i1*4, 440-i1*3, 320, 48);
pictureBox4->SetBounds(440-4*i1, 440, 320, 48);
}
if ((n>=30)&&(n<50))
{i2++;
pictureBox1->SetBounds(440, 140+i2*3, 320, 48);
pictureBox2->SetBounds(40+i2*4, 440, 320, 48);
pictureBox3->SetBounds(440-i2*4, 140, 320, 48);
pictureBox4->SetBounds(40, 440-i2*3, 320, 48);
}
if ((n>=60))
{i3++;
pictureBox1->SetBounds(440-i3*4, 440-i3*3, 320, 48);
pictureBox2->SetBounds(440, 440-i3*3, 320, 48);
pictureBox3->SetBounds(40, 140+i3*3, 320, 48);
pictureBox4->SetBounds(40+i3*4, 140+i3*3, 320, 48);
}

if (n==80)
{
	n=-10;
	i1=0;
	i2=0;
	i3=0;
}
		 }
// ÍÌÓÔÍ‡ ¬€’Œƒ
private: System::Void button31_Click(System::Object^  sender, System::EventArgs^  e) {
			 Close();
		 }

		 // ÔÓ‰Ò˜ÂÚ ˜ËÒÎ‡ ÏÂÒÚ ÔÓ ÚËÔ‡Ï ‚‡„ÓÌÓ‚
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
// ÒË‰ˇ˜ËÂ			 
listBox4->Items->Clear();
listBox4->Items->Add(36-WagonPas23->getseats());
// ÔÎ‡ˆÍ‡ÚÌ˚Â
listBox6->Items->Clear();
listBox6->Items->Add(72-WagonPas31->getseats()-WagonPas32->getseats());
// ÍÛÔÂÈÌ˚Â
listBox2->Items->Clear();
listBox2->Items->Add(108-WagonPas13->getseats()-WagonPas21->getseats()-WagonPas41->getseats());
// ÍÛÔÂÈÌ˚Â Ò ÚÂÎÂ‚ËÁÓÓÏ
listBox8->Items->Clear();
listBox8->Items->Add(8-WagonPas11->getseats()-WagonPas42->getseats());
// ÍÛÔÂÈÌ˚Â Ò ÚÂÎÂÙÓÌÓÏ
listBox15->Items->Clear();
listBox15->Items->Add(36-WagonPas43->getseats());
		 }

private: System::Void button7_Click(System::Object^  sender, System::EventArgs^  e) {
listBox37->Items->Clear();
listBox37->Items->Add(mar1);
listBox25->Items->Clear();
listBox25->Items->Add(mar2);
listBox33->Items->Clear();
listBox33->Items->Add(mar3);
listBox36->Items->Clear();
listBox36->Items->Add(mar4);
listBox24->Items->Clear();
listBox24->Items->Add(mar5);
listBox32->Items->Clear();
listBox32->Items->Add(mar6);

listBox35->Items->Clear();
listBox35->Items->Add(mar7);
listBox23->Items->Clear();
listBox23->Items->Add(mar8);
listBox27->Items->Clear();
listBox27->Items->Add(mar9);
listBox34->Items->Clear();
listBox34->Items->Add(mar10);
listBox22->Items->Clear();
listBox22->Items->Add(mar11);
listBox26->Items->Clear();
listBox26->Items->Add(mar12);
		 
		 }
private: System::Void button8_Click(System::Object^  sender, System::EventArgs^  e) {
			 listBox17->Items->Clear();
			 listBox17->Items->Add(pri1);
			 listBox16->Items->Clear();
			 listBox16->Items->Add(pri2);
			 listBox18->Items->Clear();
			 listBox18->Items->Add(pri3);
			 listBox19->Items->Clear();
			 listBox19->Items->Add(pri4);
			 listBox14->Items->Clear();
			 listBox14->Items->Add(price);

		 }
private: System::Void button9_Click(System::Object^  sender, System::EventArgs^  e) {
             listBox40->Items->Clear();
			 listBox40->Items->Add(pr1);
			 listBox39->Items->Clear();
			 listBox39->Items->Add(pr2);
			 listBox38->Items->Clear();
			 listBox38->Items->Add(pr3);
			 listBox21->Items->Clear();
			 listBox21->Items->Add(pr4);
			 listBox20->Items->Clear();
			 listBox20->Items->Add(price);

		 }
private: System::Void button29_Click(System::Object^  sender, System::EventArgs^  e) {
			 listBox45->Items->Clear();
			 listBox45->Items->Add(price1);
			 listBox44->Items->Clear();
			 listBox44->Items->Add(price2);
			 listBox43->Items->Clear();
			 listBox43->Items->Add(price3);
			 listBox42->Items->Clear();
			 listBox42->Items->Add(price4);
             listBox46->Items->Clear();
			 listBox46->Items->Add(price5);
			 listBox41->Items->Clear();
			 listBox41->Items->Add(price);

		 }
private: System::Void ÛÍÓ‚Ó‰ÒÚ‚ÓœÓÎ¸ÁÓ‚‡ÚÂÎˇToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 MessageBox::Show("œÓ„‡ÏÏ‡ ‡Á‡·ÓÚ‡Ì‡ ‰Îˇ Ì‡„Îˇ‰ÌÓÈ ËÏËÚ‡ˆËË ‰‚ËÊÂÌËˇ ÔÓÂÁ‰Ó‚ ÏÂÊ‰Û ÒÚ‡ÌˆËˇÏË.  ÌÓÔÍË ‚ÍÎ˛˜ÂÌËˇ/ÓÒÚ‡ÌÓ‚‡ ÔÓˆÂÒÒ‡ - œ”— /—“Œœ.  ÌÓÔÍË  ÛÔËÚ¸ ·ËÎÂÚ - ‰Îˇ ÔÓÍÛÔÍË ·ËÎÂÚÓ‚ Ì‡ Í‡Ê‰ÓÈ ÒÚ‡ÌˆËË.");
		 }
};
}

