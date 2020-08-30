namespace Instructions_for_CM9
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.Connect = new System.Windows.Forms.Button();
            this.serialPort = new System.IO.Ports.SerialPort(this.components);
            this.Request = new System.Windows.Forms.Button();
            this.label3 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.X_Value = new System.Windows.Forms.TextBox();
            this.X_trackBar = new System.Windows.Forms.TrackBar();
            this.y_trackBar = new System.Windows.Forms.TrackBar();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.label14 = new System.Windows.Forms.Label();
            this.label13 = new System.Windows.Forms.Label();
            this.listBox1 = new System.Windows.Forms.ListBox();
            this.Til = new System.Windows.Forms.TextBox();
            this.T_H = new System.Windows.Forms.TextBox();
            this.T_L = new System.Windows.Forms.TextBox();
            this.label10 = new System.Windows.Forms.Label();
            this.P_L = new System.Windows.Forms.TextBox();
            this.P_H = new System.Windows.Forms.TextBox();
            this.Pan = new System.Windows.Forms.TextBox();
            this.label6 = new System.Windows.Forms.Label();
            this.label12 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.Y = new System.Windows.Forms.TextBox();
            this.X = new System.Windows.Forms.TextBox();
            this.checkBox1 = new System.Windows.Forms.CheckBox();
            this.button2 = new System.Windows.Forms.Button();
            this.label7 = new System.Windows.Forms.Label();
            this.label8 = new System.Windows.Forms.Label();
            this.label9 = new System.Windows.Forms.Label();
            this.Y_Value = new System.Windows.Forms.TextBox();
            this.label11 = new System.Windows.Forms.Label();
            this.Z_Value = new System.Windows.Forms.TextBox();
            this.Sending_instructions = new System.Windows.Forms.Button();
            this.GY80 = new System.Windows.Forms.Button();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.groupBox3 = new System.Windows.Forms.GroupBox();
            this.groupBox6 = new System.Windows.Forms.GroupBox();
            this.radioButton7 = new System.Windows.Forms.RadioButton();
            this.radioButton8 = new System.Windows.Forms.RadioButton();
            this.radioButton9 = new System.Windows.Forms.RadioButton();
            this.Right_Kick = new System.Windows.Forms.CheckBox();
            this.Left_Kick = new System.Windows.Forms.CheckBox();
            this.groupBox5 = new System.Windows.Forms.GroupBox();
            this.radioButton4 = new System.Windows.Forms.RadioButton();
            this.Rotate_Speed_Combo = new System.Windows.Forms.ComboBox();
            this.radioButton5 = new System.Windows.Forms.RadioButton();
            this.radioButton6 = new System.Windows.Forms.RadioButton();
            this.groupBox4 = new System.Windows.Forms.GroupBox();
            this.radioButton3 = new System.Windows.Forms.RadioButton();
            this.Walking_Speed_Combo = new System.Windows.Forms.ComboBox();
            this.radioButton2 = new System.Windows.Forms.RadioButton();
            this.radioButton1 = new System.Windows.Forms.RadioButton();
            ((System.ComponentModel.ISupportInitialize)(this.X_trackBar)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.y_trackBar)).BeginInit();
            this.groupBox1.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.groupBox3.SuspendLayout();
            this.groupBox6.SuspendLayout();
            this.groupBox5.SuspendLayout();
            this.groupBox4.SuspendLayout();
            this.SuspendLayout();
            // 
            // Connect
            // 
            this.Connect.Location = new System.Drawing.Point(413, 11);
            this.Connect.Name = "Connect";
            this.Connect.Size = new System.Drawing.Size(87, 33);
            this.Connect.TabIndex = 1;
            this.Connect.Text = "Conecting";
            this.Connect.UseVisualStyleBackColor = true;
            this.Connect.Click += new System.EventHandler(this.button1_Click);
            // 
            // Request
            // 
            this.Request.Enabled = false;
            this.Request.Location = new System.Drawing.Point(385, 267);
            this.Request.Name = "Request";
            this.Request.Size = new System.Drawing.Size(125, 35);
            this.Request.TabIndex = 14;
            this.Request.Text = "Request data From Head Motors";
            this.Request.UseVisualStyleBackColor = true;
            this.Request.Click += new System.EventHandler(this.button3_Click);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(93, 11);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(0, 13);
            this.label3.TabIndex = 13;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(27, 18);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(0, 13);
            this.label2.TabIndex = 12;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(238, 430);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(0, 13);
            this.label1.TabIndex = 9;
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(173, 93);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(0, 13);
            this.label4.TabIndex = 15;
            // 
            // X_Value
            // 
            this.X_Value.Enabled = false;
            this.X_Value.Location = new System.Drawing.Point(43, 23);
            this.X_Value.Name = "X_Value";
            this.X_Value.Size = new System.Drawing.Size(40, 20);
            this.X_Value.TabIndex = 16;
            // 
            // X_trackBar
            // 
            this.X_trackBar.Enabled = false;
            this.X_trackBar.Location = new System.Drawing.Point(13, 197);
            this.X_trackBar.Maximum = 4095;
            this.X_trackBar.Minimum = 1;
            this.X_trackBar.Name = "X_trackBar";
            this.X_trackBar.Size = new System.Drawing.Size(222, 45);
            this.X_trackBar.TabIndex = 17;
            this.X_trackBar.Value = 2047;
            this.X_trackBar.Scroll += new System.EventHandler(this.X_trackBar_Scroll);
            // 
            // y_trackBar
            // 
            this.y_trackBar.Enabled = false;
            this.y_trackBar.Location = new System.Drawing.Point(241, 9);
            this.y_trackBar.Maximum = 4095;
            this.y_trackBar.Name = "y_trackBar";
            this.y_trackBar.Orientation = System.Windows.Forms.Orientation.Vertical;
            this.y_trackBar.Size = new System.Drawing.Size(45, 220);
            this.y_trackBar.TabIndex = 18;
            this.y_trackBar.Value = 2047;
            this.y_trackBar.Scroll += new System.EventHandler(this.Y_trackBar_Scroll);
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.label14);
            this.groupBox1.Controls.Add(this.label13);
            this.groupBox1.Controls.Add(this.listBox1);
            this.groupBox1.Controls.Add(this.Request);
            this.groupBox1.Controls.Add(this.Til);
            this.groupBox1.Controls.Add(this.T_H);
            this.groupBox1.Controls.Add(this.T_L);
            this.groupBox1.Controls.Add(this.label10);
            this.groupBox1.Controls.Add(this.P_L);
            this.groupBox1.Controls.Add(this.P_H);
            this.groupBox1.Controls.Add(this.Pan);
            this.groupBox1.Controls.Add(this.label6);
            this.groupBox1.Controls.Add(this.label12);
            this.groupBox1.Controls.Add(this.label5);
            this.groupBox1.Controls.Add(this.Y);
            this.groupBox1.Controls.Add(this.X);
            this.groupBox1.Controls.Add(this.y_trackBar);
            this.groupBox1.Controls.Add(this.X_trackBar);
            this.groupBox1.Location = new System.Drawing.Point(36, 40);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(516, 308);
            this.groupBox1.TabIndex = 19;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Head motors Controller";
            // 
            // label14
            // 
            this.label14.AutoSize = true;
            this.label14.Location = new System.Drawing.Point(357, 205);
            this.label14.Name = "label14";
            this.label14.Size = new System.Drawing.Size(132, 13);
            this.label14.TabIndex = 41;
            this.label14.Text = "Present Position Of Motors";
            // 
            // label13
            // 
            this.label13.AutoSize = true;
            this.label13.Enabled = false;
            this.label13.Location = new System.Drawing.Point(437, 247);
            this.label13.Name = "label13";
            this.label13.Size = new System.Drawing.Size(21, 13);
            this.label13.TabIndex = 40;
            this.label13.Text = "Tilt";
            // 
            // listBox1
            // 
            this.listBox1.FormattingEnabled = true;
            this.listBox1.Location = new System.Drawing.Point(360, 9);
            this.listBox1.Name = "listBox1";
            this.listBox1.Size = new System.Drawing.Size(150, 186);
            this.listBox1.TabIndex = 31;
            // 
            // Til
            // 
            this.Til.Enabled = false;
            this.Til.Location = new System.Drawing.Point(458, 244);
            this.Til.Name = "Til";
            this.Til.Size = new System.Drawing.Size(53, 20);
            this.Til.TabIndex = 38;
            // 
            // T_H
            // 
            this.T_H.Enabled = false;
            this.T_H.Location = new System.Drawing.Point(485, 222);
            this.T_H.Name = "T_H";
            this.T_H.Size = new System.Drawing.Size(25, 20);
            this.T_H.TabIndex = 34;
            // 
            // T_L
            // 
            this.T_L.Enabled = false;
            this.T_L.Location = new System.Drawing.Point(458, 222);
            this.T_L.Name = "T_L";
            this.T_L.Size = new System.Drawing.Size(24, 20);
            this.T_L.TabIndex = 35;
            // 
            // label10
            // 
            this.label10.AutoSize = true;
            this.label10.Font = new System.Drawing.Font("Segoe Script", 48F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label10.Location = new System.Drawing.Point(40, 53);
            this.label10.Name = "label10";
            this.label10.Size = new System.Drawing.Size(168, 106);
            this.label10.TabIndex = 23;
            this.label10.Text = "IRC";
            // 
            // P_L
            // 
            this.P_L.Enabled = false;
            this.P_L.Location = new System.Drawing.Point(385, 221);
            this.P_L.Name = "P_L";
            this.P_L.Size = new System.Drawing.Size(23, 20);
            this.P_L.TabIndex = 33;
            // 
            // P_H
            // 
            this.P_H.Enabled = false;
            this.P_H.Location = new System.Drawing.Point(412, 221);
            this.P_H.Name = "P_H";
            this.P_H.Size = new System.Drawing.Size(24, 20);
            this.P_H.TabIndex = 32;
            // 
            // Pan
            // 
            this.Pan.Enabled = false;
            this.Pan.Location = new System.Drawing.Point(385, 244);
            this.Pan.Name = "Pan";
            this.Pan.Size = new System.Drawing.Size(51, 20);
            this.Pan.TabIndex = 37;
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(281, 179);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(44, 13);
            this.label6.TabIndex = 22;
            this.label6.Text = "Y Motor";
            // 
            // label12
            // 
            this.label12.AutoSize = true;
            this.label12.Enabled = false;
            this.label12.Location = new System.Drawing.Point(357, 247);
            this.label12.Name = "label12";
            this.label12.Size = new System.Drawing.Size(26, 13);
            this.label12.TabIndex = 24;
            this.label12.Text = "Pan";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(145, 247);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(44, 13);
            this.label5.TabIndex = 21;
            this.label5.Text = "X Motor";
            // 
            // Y
            // 
            this.Y.Enabled = false;
            this.Y.Location = new System.Drawing.Point(281, 201);
            this.Y.Name = "Y";
            this.Y.Size = new System.Drawing.Size(44, 20);
            this.Y.TabIndex = 20;
            // 
            // X
            // 
            this.X.Enabled = false;
            this.X.Location = new System.Drawing.Point(191, 244);
            this.X.Name = "X";
            this.X.Size = new System.Drawing.Size(44, 20);
            this.X.TabIndex = 19;
            // 
            // checkBox1
            // 
            this.checkBox1.AutoSize = true;
            this.checkBox1.Checked = true;
            this.checkBox1.CheckState = System.Windows.Forms.CheckState.Checked;
            this.checkBox1.Enabled = false;
            this.checkBox1.Location = new System.Drawing.Point(274, 24);
            this.checkBox1.Name = "checkBox1";
            this.checkBox1.Size = new System.Drawing.Size(108, 17);
            this.checkBox1.TabIndex = 19;
            this.checkBox1.Text = "Update Real-time";
            this.checkBox1.UseVisualStyleBackColor = true;
            // 
            // button2
            // 
            this.button2.Location = new System.Drawing.Point(500, 12);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(52, 31);
            this.button2.TabIndex = 23;
            this.button2.Text = "Exit";
            this.button2.UseVisualStyleBackColor = true;
            this.button2.Click += new System.EventHandler(this.button2_Click_1);
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(15, 400);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(0, 13);
            this.label7.TabIndex = 24;
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Location = new System.Drawing.Point(23, 27);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(14, 13);
            this.label8.TabIndex = 25;
            this.label8.Text = "X";
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.Location = new System.Drawing.Point(85, 27);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(14, 13);
            this.label9.TabIndex = 27;
            this.label9.Text = "Y";
            // 
            // Y_Value
            // 
            this.Y_Value.Enabled = false;
            this.Y_Value.Location = new System.Drawing.Point(100, 23);
            this.Y_Value.Name = "Y_Value";
            this.Y_Value.Size = new System.Drawing.Size(40, 20);
            this.Y_Value.TabIndex = 26;
            // 
            // label11
            // 
            this.label11.AutoSize = true;
            this.label11.Location = new System.Drawing.Point(142, 27);
            this.label11.Name = "label11";
            this.label11.Size = new System.Drawing.Size(14, 13);
            this.label11.TabIndex = 29;
            this.label11.Text = "Z";
            // 
            // Z_Value
            // 
            this.Z_Value.Enabled = false;
            this.Z_Value.Location = new System.Drawing.Point(159, 23);
            this.Z_Value.Name = "Z_Value";
            this.Z_Value.Size = new System.Drawing.Size(40, 20);
            this.Z_Value.TabIndex = 28;
            // 
            // Sending_instructions
            // 
            this.Sending_instructions.Enabled = false;
            this.Sending_instructions.Location = new System.Drawing.Point(433, 19);
            this.Sending_instructions.Name = "Sending_instructions";
            this.Sending_instructions.Size = new System.Drawing.Size(77, 36);
            this.Sending_instructions.TabIndex = 39;
            this.Sending_instructions.Text = "Sending Instructions";
            this.Sending_instructions.UseVisualStyleBackColor = true;
            this.Sending_instructions.Click += new System.EventHandler(this.button4_Click);
            // 
            // GY80
            // 
            this.GY80.Enabled = false;
            this.GY80.Location = new System.Drawing.Point(434, 15);
            this.GY80.Name = "GY80";
            this.GY80.Size = new System.Drawing.Size(76, 35);
            this.GY80.TabIndex = 40;
            this.GY80.Text = "Start GY8";
            this.GY80.UseVisualStyleBackColor = true;
            this.GY80.Click += new System.EventHandler(this.button1_Click_2);
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.Z_Value);
            this.groupBox2.Controls.Add(this.GY80);
            this.groupBox2.Controls.Add(this.label2);
            this.groupBox2.Controls.Add(this.label3);
            this.groupBox2.Controls.Add(this.X_Value);
            this.groupBox2.Controls.Add(this.label11);
            this.groupBox2.Controls.Add(this.label8);
            this.groupBox2.Controls.Add(this.Y_Value);
            this.groupBox2.Controls.Add(this.label9);
            this.groupBox2.Location = new System.Drawing.Point(36, 354);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(516, 59);
            this.groupBox2.TabIndex = 41;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "GY80";
            // 
            // groupBox3
            // 
            this.groupBox3.Controls.Add(this.groupBox6);
            this.groupBox3.Controls.Add(this.Right_Kick);
            this.groupBox3.Controls.Add(this.Left_Kick);
            this.groupBox3.Controls.Add(this.groupBox5);
            this.groupBox3.Controls.Add(this.groupBox4);
            this.groupBox3.Controls.Add(this.Sending_instructions);
            this.groupBox3.Location = new System.Drawing.Point(36, 419);
            this.groupBox3.Name = "groupBox3";
            this.groupBox3.Size = new System.Drawing.Size(516, 105);
            this.groupBox3.TabIndex = 42;
            this.groupBox3.TabStop = false;
            this.groupBox3.Text = "Behaviours";
            // 
            // groupBox6
            // 
            this.groupBox6.Controls.Add(this.radioButton7);
            this.groupBox6.Controls.Add(this.radioButton8);
            this.groupBox6.Controls.Add(this.radioButton9);
            this.groupBox6.Location = new System.Drawing.Point(331, 19);
            this.groupBox6.Name = "groupBox6";
            this.groupBox6.Size = new System.Drawing.Size(96, 80);
            this.groupBox6.TabIndex = 44;
            this.groupBox6.TabStop = false;
            this.groupBox6.Text = "Side Walk";
            // 
            // radioButton7
            // 
            this.radioButton7.AutoSize = true;
            this.radioButton7.Location = new System.Drawing.Point(9, 55);
            this.radioButton7.Name = "radioButton7";
            this.radioButton7.Size = new System.Drawing.Size(79, 17);
            this.radioButton7.TabIndex = 43;
            this.radioButton7.Text = "Go to Right";
            this.radioButton7.UseVisualStyleBackColor = true;
            this.radioButton7.CheckedChanged += new System.EventHandler(this.radioButton7_CheckedChanged);
            // 
            // radioButton8
            // 
            this.radioButton8.AutoSize = true;
            this.radioButton8.Location = new System.Drawing.Point(9, 35);
            this.radioButton8.Name = "radioButton8";
            this.radioButton8.Size = new System.Drawing.Size(72, 17);
            this.radioButton8.TabIndex = 42;
            this.radioButton8.Text = "Go to Left";
            this.radioButton8.UseVisualStyleBackColor = true;
            this.radioButton8.CheckedChanged += new System.EventHandler(this.radioButton8_CheckedChanged);
            // 
            // radioButton9
            // 
            this.radioButton9.AutoSize = true;
            this.radioButton9.Checked = true;
            this.radioButton9.Location = new System.Drawing.Point(9, 17);
            this.radioButton9.Name = "radioButton9";
            this.radioButton9.Size = new System.Drawing.Size(47, 17);
            this.radioButton9.TabIndex = 41;
            this.radioButton9.TabStop = true;
            this.radioButton9.Text = "Stop";
            this.radioButton9.UseVisualStyleBackColor = true;
            // 
            // Right_Kick
            // 
            this.Right_Kick.AutoSize = true;
            this.Right_Kick.Location = new System.Drawing.Point(434, 79);
            this.Right_Kick.Name = "Right_Kick";
            this.Right_Kick.Size = new System.Drawing.Size(75, 17);
            this.Right_Kick.TabIndex = 43;
            this.Right_Kick.Text = "Right Kick";
            this.Right_Kick.UseVisualStyleBackColor = true;
            this.Right_Kick.CheckedChanged += new System.EventHandler(this.Right_Kick_CheckedChanged);
            // 
            // Left_Kick
            // 
            this.Left_Kick.AutoSize = true;
            this.Left_Kick.Location = new System.Drawing.Point(434, 60);
            this.Left_Kick.Name = "Left_Kick";
            this.Left_Kick.Size = new System.Drawing.Size(68, 17);
            this.Left_Kick.TabIndex = 42;
            this.Left_Kick.Text = "Left Kick";
            this.Left_Kick.UseVisualStyleBackColor = true;
            this.Left_Kick.CheckedChanged += new System.EventHandler(this.Left_Kick_CheckedChanged);
            // 
            // groupBox5
            // 
            this.groupBox5.Controls.Add(this.radioButton4);
            this.groupBox5.Controls.Add(this.Rotate_Speed_Combo);
            this.groupBox5.Controls.Add(this.radioButton5);
            this.groupBox5.Controls.Add(this.radioButton6);
            this.groupBox5.Location = new System.Drawing.Point(170, 19);
            this.groupBox5.Name = "groupBox5";
            this.groupBox5.Size = new System.Drawing.Size(155, 80);
            this.groupBox5.TabIndex = 41;
            this.groupBox5.TabStop = false;
            this.groupBox5.Text = "Rotate";
            // 
            // radioButton4
            // 
            this.radioButton4.AutoSize = true;
            this.radioButton4.Location = new System.Drawing.Point(8, 55);
            this.radioButton4.Name = "radioButton4";
            this.radioButton4.Size = new System.Drawing.Size(97, 17);
            this.radioButton4.TabIndex = 43;
            this.radioButton4.Text = "Rotate to Right";
            this.radioButton4.UseVisualStyleBackColor = true;
            this.radioButton4.CheckedChanged += new System.EventHandler(this.radioButton4_CheckedChanged);
            // 
            // Rotate_Speed_Combo
            // 
            this.Rotate_Speed_Combo.FormattingEnabled = true;
            this.Rotate_Speed_Combo.Items.AddRange(new object[] {
            "1",
            "2",
            "3",
            "4",
            "5",
            "6"});
            this.Rotate_Speed_Combo.Location = new System.Drawing.Point(103, 41);
            this.Rotate_Speed_Combo.Name = "Rotate_Speed_Combo";
            this.Rotate_Speed_Combo.Size = new System.Drawing.Size(43, 21);
            this.Rotate_Speed_Combo.TabIndex = 41;
            // 
            // radioButton5
            // 
            this.radioButton5.AutoSize = true;
            this.radioButton5.Location = new System.Drawing.Point(8, 35);
            this.radioButton5.Name = "radioButton5";
            this.radioButton5.Size = new System.Drawing.Size(90, 17);
            this.radioButton5.TabIndex = 42;
            this.radioButton5.Text = "Rotate to Left";
            this.radioButton5.UseVisualStyleBackColor = true;
            this.radioButton5.CheckedChanged += new System.EventHandler(this.radioButton5_CheckedChanged);
            // 
            // radioButton6
            // 
            this.radioButton6.AutoSize = true;
            this.radioButton6.Checked = true;
            this.radioButton6.Location = new System.Drawing.Point(8, 17);
            this.radioButton6.Name = "radioButton6";
            this.radioButton6.Size = new System.Drawing.Size(47, 17);
            this.radioButton6.TabIndex = 41;
            this.radioButton6.TabStop = true;
            this.radioButton6.Text = "Stop";
            this.radioButton6.UseVisualStyleBackColor = true;
            // 
            // groupBox4
            // 
            this.groupBox4.Controls.Add(this.radioButton3);
            this.groupBox4.Controls.Add(this.Walking_Speed_Combo);
            this.groupBox4.Controls.Add(this.radioButton2);
            this.groupBox4.Controls.Add(this.radioButton1);
            this.groupBox4.Location = new System.Drawing.Point(14, 19);
            this.groupBox4.Name = "groupBox4";
            this.groupBox4.Size = new System.Drawing.Size(152, 80);
            this.groupBox4.TabIndex = 40;
            this.groupBox4.TabStop = false;
            this.groupBox4.Text = "Walking";
            // 
            // radioButton3
            // 
            this.radioButton3.AutoSize = true;
            this.radioButton3.Location = new System.Drawing.Point(9, 55);
            this.radioButton3.Name = "radioButton3";
            this.radioButton3.Size = new System.Drawing.Size(50, 17);
            this.radioButton3.TabIndex = 43;
            this.radioButton3.Text = "Walk";
            this.radioButton3.UseVisualStyleBackColor = true;
            this.radioButton3.CheckedChanged += new System.EventHandler(this.radioButton3_CheckedChanged);
            // 
            // Walking_Speed_Combo
            // 
            this.Walking_Speed_Combo.FormattingEnabled = true;
            this.Walking_Speed_Combo.Items.AddRange(new object[] {
            "1",
            "2",
            "3",
            "4",
            "5",
            "6"});
            this.Walking_Speed_Combo.Location = new System.Drawing.Point(104, 41);
            this.Walking_Speed_Combo.Name = "Walking_Speed_Combo";
            this.Walking_Speed_Combo.Size = new System.Drawing.Size(43, 21);
            this.Walking_Speed_Combo.TabIndex = 41;
            // 
            // radioButton2
            // 
            this.radioButton2.AutoSize = true;
            this.radioButton2.Location = new System.Drawing.Point(9, 35);
            this.radioButton2.Name = "radioButton2";
            this.radioButton2.Size = new System.Drawing.Size(92, 17);
            this.radioButton2.TabIndex = 42;
            this.radioButton2.Text = "In Place Walk";
            this.radioButton2.UseVisualStyleBackColor = true;
            this.radioButton2.CheckedChanged += new System.EventHandler(this.radioButton2_CheckedChanged);
            // 
            // radioButton1
            // 
            this.radioButton1.AutoSize = true;
            this.radioButton1.Checked = true;
            this.radioButton1.Location = new System.Drawing.Point(9, 17);
            this.radioButton1.Name = "radioButton1";
            this.radioButton1.Size = new System.Drawing.Size(47, 17);
            this.radioButton1.TabIndex = 41;
            this.radioButton1.TabStop = true;
            this.radioButton1.Text = "Stop";
            this.radioButton1.UseVisualStyleBackColor = true;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(586, 536);
            this.Controls.Add(this.groupBox3);
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.Connect);
            this.Controls.Add(this.label7);
            this.Controls.Add(this.button2);
            this.Controls.Add(this.checkBox1);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label1);
            this.Name = "Form1";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "text";
            this.Load += new System.EventHandler(this.Form1_Load);
            ((System.ComponentModel.ISupportInitialize)(this.X_trackBar)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.y_trackBar)).EndInit();
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            this.groupBox3.ResumeLayout(false);
            this.groupBox3.PerformLayout();
            this.groupBox6.ResumeLayout(false);
            this.groupBox6.PerformLayout();
            this.groupBox5.ResumeLayout(false);
            this.groupBox5.PerformLayout();
            this.groupBox4.ResumeLayout(false);
            this.groupBox4.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button Connect;
        private System.IO.Ports.SerialPort serialPort;
        private System.Windows.Forms.Button Request;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.TextBox X_Value;
        private System.Windows.Forms.TrackBar X_trackBar;
        private System.Windows.Forms.TrackBar y_trackBar;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.CheckBox checkBox1;
        private System.Windows.Forms.TextBox Y;
        private System.Windows.Forms.TextBox X;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.TextBox Y_Value;
        private System.Windows.Forms.Label label10;
        private System.Windows.Forms.Label label11;
        private System.Windows.Forms.TextBox Z_Value;
        private System.Windows.Forms.ListBox listBox1;
        private System.Windows.Forms.TextBox P_H;
        private System.Windows.Forms.TextBox P_L;
        private System.Windows.Forms.TextBox T_H;
        private System.Windows.Forms.TextBox T_L;
        private System.Windows.Forms.Label label12;
        private System.Windows.Forms.TextBox Pan;
        private System.Windows.Forms.TextBox Til;
        private System.Windows.Forms.Button Sending_instructions;
        private System.Windows.Forms.Label label14;
        private System.Windows.Forms.Label label13;
        private System.Windows.Forms.Button GY80;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.GroupBox groupBox3;
        private System.Windows.Forms.GroupBox groupBox4;
        private System.Windows.Forms.ComboBox Walking_Speed_Combo;
        private System.Windows.Forms.RadioButton radioButton2;
        private System.Windows.Forms.RadioButton radioButton1;
        private System.Windows.Forms.RadioButton radioButton3;
        private System.Windows.Forms.GroupBox groupBox5;
        private System.Windows.Forms.RadioButton radioButton4;
        private System.Windows.Forms.ComboBox Rotate_Speed_Combo;
        private System.Windows.Forms.RadioButton radioButton5;
        private System.Windows.Forms.RadioButton radioButton6;
        private System.Windows.Forms.CheckBox Left_Kick;
        private System.Windows.Forms.CheckBox Right_Kick;
        private System.Windows.Forms.GroupBox groupBox6;
        private System.Windows.Forms.RadioButton radioButton7;
        private System.Windows.Forms.RadioButton radioButton8;
        private System.Windows.Forms.RadioButton radioButton9;
    }
}

