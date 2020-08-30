using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

using System.Threading;
using System.IO.Ports;

namespace Instructions_for_CM9
{    
    public partial class Form1 : Form
    {
        //Global Defenition of low and high byte of integer registers  const double DEG2DXL = 11.377777776666666668;
        bool request=true;
        const double DXL2DEG = 0.0879120879120879;
        ManualResetEvent m_stopThreadsEvent = new ManualResetEvent(false);

        public Form1()
        {
            InitializeComponent();
        }
        //*********************************************************
        private void button1_Click(object sender, EventArgs e)
        {
            serialPort.PortName = "COM8";
            try
            {
                serialPort.Open();
                label4.Text = "Connected";

                Connect.Enabled = false;
                Connect.Enabled = false;
                Request.Enabled = true;
                y_trackBar.Enabled = true;
                X_trackBar.Enabled = true;
                GY80.Enabled = true;
                Sending_instructions.Enabled = true;
            }
            catch
            {
                MessageBox.Show("Error in Connection!");
            }
         
        }
        //*********************************************************
        private void button2_Click(object sender, EventArgs e)
        {

        }
        //*********************************************************
        private void button3_Click(object sender, EventArgs e)
        {
            Thread thread_one = new Thread(new ThreadStart(Thread1));
            thread_one.SetApartmentState(ApartmentState.STA);
            thread_one.Start();

        }
        //*********************************************************
        public void Thread1()
        {
            // try
            {
               // while (request)
                {
                    serialPort.ReadExisting();
                    byte[] data = new byte[8];
                    data[0] = 75;
                    data[1] = 75;
                    data[2] = 75;
                    serialPort.Write(data, 0, 3);

                    byte[] d = new byte[10];

                    label1.Text = "";
                    if (serialPort.ReadChar() == 65)
                        if (serialPort.ReadChar() == 65)
                        {
                            for (int i = 0; i <= 3; i++)
                            {
                                d[i] = Convert.ToByte(serialPort.ReadChar());
                            }

                            P_L.Invoke(new Action(() => P_L.Text = d[0].ToString()));
                            P_H.Invoke(new Action(() => P_H.Text = d[1].ToString()));

                            T_L.Invoke(new Action(() => T_L.Text = d[2].ToString()));
                            T_H.Invoke(new Action(() => T_H.Text = d[3].ToString()));

                            double Pan_Position = (((d[1] * 100) + d[0]));
                            double Til_Position = (((d[3] * 100) + d[2]));

                            Pan.Invoke(new Action(() => Pan.Text = Pan_Position.ToString()));
                            Til.Invoke(new Action(() => Til.Text = Til_Position.ToString()));

                           // listBox1.Invoke(new Action(() => listBox1.Items.Add(Pan_Position.ToString())));

                           // listBox1.Invoke(new Action(() => listBox1.Items.Add("------------------"))); 

                         //   listBox1.Invoke(new Action(() => T_L.Text = d[2].ToString()));
                         //   listBox1.Invoke(new Action(() => T_H.Text = d[3].ToString()));
                            // 
                        }
                    System.Threading.Thread.Sleep(100);
                }
             
            }
            // catch
            {

            }
        }
        //*********************************************************
        private void X_trackBar_Scroll(object sender, EventArgs e)
        {
            X.Text = X_trackBar.Value.ToString();

            byte[] data = new byte[8];
            data[0] = 99;
            data[1] = 99;

            int send_x_H = X_trackBar.Value / 100;
            int send_x_L = X_trackBar.Value - (send_x_H * 100);

            int send_y_H = y_trackBar.Value / 100;
            int send_y_L = y_trackBar.Value - (send_y_H * 100);

            data[2] = Convert.ToByte(send_x_H);     // Convert.ToByte(Convert.ToInt32(H_x));
            data[3] = Convert.ToByte(send_x_L);  // Convert.ToByte(Convert.ToInt32(L_x));

            data[4] = Convert.ToByte(send_y_H);     // Convert.ToByte(Convert.ToInt32(H_x));
            data[5] = Convert.ToByte(send_y_L);  // Convert.ToByte(Convert.ToInt32(L_x));

            serialPort.Write(data, 0, 6);
       }
        //********************************************************
        private void Y_trackBar_Scroll(object sender, EventArgs e)
        {
            Y.Text = y_trackBar.Value.ToString();

            byte[] data = new byte[8];
            data[0] = 99;
            data[1] = 99;

            int send_x_H = X_trackBar.Value / 100;
            int send_x_L = X_trackBar.Value - (send_x_H * 100);

            int send_y_H = y_trackBar.Value / 100;
            int send_y_L = y_trackBar.Value - (send_y_H * 100);

            data[2] = Convert.ToByte(send_x_H);     // Convert.ToByte(Convert.ToInt32(H_x));
            data[3] = Convert.ToByte(send_x_L);  // Convert.ToByte(Convert.ToInt32(L_x));

            data[4] = Convert.ToByte(send_y_H);     // Convert.ToByte(Convert.ToInt32(H_x));
            data[5] = Convert.ToByte(send_y_L);  // Convert.ToByte(Convert.ToInt32(L_x));

            serialPort.Write(data, 0, 6);

        }
        //*********************************************************
        private void Form1_Load(object sender, EventArgs e)
        {
            Y.Text = y_trackBar.Value.ToString();
            X.Text = X_trackBar.Value.ToString();
            Walking_Speed_Combo.SelectedItem = "5";
            Rotate_Speed_Combo.SelectedItem = "5";          
        }
        //*********************************************************
        private void button1_Click_1(object sender, EventArgs e)
        {
          //  y_trackBar.Value = 127;
          //  X_trackBar.Value = 127;
            Y.Text = y_trackBar.Value.ToString();
            X.Text = X_trackBar.Value.ToString();
        }
        //*********************************************************
        private void button2_Click_1(object sender, EventArgs e)
        {
            this.Close();
        }
        //*********************************************************
        private void Connection_FormClosing(object sender, FormClosingEventArgs e)
        {
            m_stopThreadsEvent.Set();
        }
        //*********************************************************
        private void button4_Click(object sender, EventArgs e)
        {
            X.Text = X_trackBar.Value.ToString();

            byte[] data = new byte[10];
            data[0] = 88;
            data[1] = 88;
            data[2] = 88;

            //---------------------------------
            byte walking_state = 0;           // (0= No Action, 1= In Place Walking, 2= Forward Walking)
            byte walking_speed = 0;           // (1 to 5 is for walking Speed in which, its converting to 1/10 in -Vx)
            byte Rotate_Direction = 0;        // (0= No Turning, 1= Turn to Left, 2= Turn to Right)
            byte Rotate_Speed = 0;            // (1 to 5, its for turning speed, its converting to 1/10 in -Vt)
            byte Kicking_instructions = 0;    // (0= No Kicking, 1 Kick left, 2= Kick Right)
            byte Side_Walk_Instructions = 0;  // (0= No Action, 1 Go to Left, 2= Go to Right)
            byte Other_Instructions = 0;      // This is Reserve data For run Another instructions 
            //---------------------------------
            if (radioButton1.Checked == true)
            {
                walking_state = 0;
            }
            else if (radioButton2.Checked == true)
            {
                walking_state = 1;
            }
            else if (radioButton3.Checked == true)
            {
                walking_state = 2;
            }
            walking_speed= Convert.ToByte(Walking_Speed_Combo.SelectedItem);           
            //---------------------------------
            if (radioButton6.Checked == true)
            {
                Rotate_Direction = 0;
            }
            else if (radioButton5.Checked == true)
            {
                Rotate_Direction = 1; //Left
            }
            else if (radioButton4.Checked == true)
            {
                Rotate_Direction = 2; //Right
            }
            Rotate_Speed = Convert.ToByte(Rotate_Speed_Combo.SelectedItem); 
            //--------------------------------
            if (Left_Kick.Checked == true)
                Kicking_instructions = 1;
            else if (Right_Kick.Checked == true)
                Kicking_instructions = 2;
            //--------------------------------
            //---------------------------------
            if (radioButton9.Checked == true)
            {
                Side_Walk_Instructions = 0;
            }
            else if (radioButton8.Checked == true)
            {
                Side_Walk_Instructions = 1; //Left
            }
            else if (radioButton7.Checked == true)
            {
                Side_Walk_Instructions = 2; //Right
            }
            //--------------------------------

            data[3] = walking_state;
            data[4] = walking_speed;
            data[5] = Rotate_Direction;
            data[6] = Rotate_Speed;
            data[7] = Kicking_instructions;
            data[8] = Side_Walk_Instructions;
            data[9] = Other_Instructions;

            serialPort.Write(data, 0, 10);
       
        }
        //*********************************************************
        private void button1_Click_2(object sender, EventArgs e)
        {
            Thread thread_two = new Thread(new ThreadStart(Thread2));
            thread_two.SetApartmentState(ApartmentState.STA);
            thread_two.Start();
            GY80.Enabled = false;
        }
        //*********************************************************
        public void Thread2()
        {
            try
            {
                while (request)
                {
                    serialPort.ReadExisting();
                    byte[] data = new byte[8];
                    data[0] = 75;
                    data[1] = 75;
                    data[2] = 75;
                    serialPort.Write(data, 0, 3);

                    int[] d = new int[10];

                    label1.Text = "";
                    if (serialPort.ReadChar() == 65)
                        if (serialPort.ReadChar() == 65)
                        {
                            for (int i = 0; i <= 9; i++)
                            {
                                d[i] = serialPort.ReadChar();
                                //label1.Text += d[i].ToString() + ", ";
                            }
                            //----------------------Getting X--------------------------------
                            if (d[2] == 0) // this is for posetive values
                            {
                                double x = (int)(d[1] << 8) + (d[0]);
                                X_Value.Invoke(new Action(() => X_Value.Text = ((x) / 100).ToString()));
                            }
                            else // this is for negetive values
                            {
                                double x = (int)(d[1] << 8) + (d[0]);
                                X_Value.Invoke(new Action(() => X_Value.Text = (-(x) / 100).ToString()));
                            }
                            //-----------------------Getting Y-------------------------------
                            if (d[5] == 0) // this is for posetive values
                            {
                                double y = (int)(d[4] << 8) + (d[3]);
                                Y_Value.Invoke(new Action(() => Y_Value.Text = ((y) / 100).ToString()));
                            }
                            else // this is for negetive values
                            {
                                double y = (int)(d[4] << 8) + (d[3]);
                                Y_Value.Invoke(new Action(() => Y_Value.Text = (-(y) / 100).ToString()));
                            }
                            //-----------------------Getting Z-------------------------------
                            if (d[8] == 0) // this is for posetive values
                            {
                                double z = (int)(d[7] << 8) + (d[6]);
                                Z_Value.Invoke(new Action(() => Z_Value.Text = ((z) / 100).ToString()));
                            }
                            else // this is for negetive values
                            {
                                double z = (int)(d[7] << 8) + (d[6]);
                                Z_Value.Invoke(new Action(() => Z_Value.Text = (-(z) / 100).ToString()));
                            }
                            //Y_Value.Text = d[4].ToString();
                        }
                    System.Threading.Thread.Sleep(100);
                }
            }
            catch
            {

            }
        }
        //*********************************************************
        private void Left_Kick_CheckedChanged(object sender, EventArgs e)
        {
            if (Left_Kick.Checked==true)
                Right_Kick.Enabled = false;
            else
                Right_Kick.Enabled = true;
            radioButton1.Checked = true;
            radioButton6.Checked = true;
            radioButton9.Checked = true;
        }
        //*********************************************************
        private void Right_Kick_CheckedChanged(object sender, EventArgs e)
        {
            if (Right_Kick.Checked == true)
                Left_Kick.Enabled = false;
            else
                Left_Kick.Enabled = true;
            radioButton1.Checked = true;
            radioButton6.Checked = true;
            radioButton9.Checked = true;
        }
        //*********************************************************
        private void radioButton8_CheckedChanged(object sender, EventArgs e)
        {
            if (radioButton8.Checked == true)
            {
                radioButton1.Checked = true;
                radioButton6.Checked = true; 
            }
        }
        //*********************************************************
        private void radioButton7_CheckedChanged(object sender, EventArgs e)
        {
            if (radioButton7.Checked == true)
            {
                radioButton1.Checked = true;
                radioButton6.Checked = true;
            }
        }
        //*********************************************************
        private void radioButton5_CheckedChanged(object sender, EventArgs e)
        {
            if (radioButton5.Checked == true)
            {
                radioButton9.Checked = true;
            }
        }
        //*********************************************************
        private void radioButton4_CheckedChanged(object sender, EventArgs e)
        {
            if (radioButton4.Checked == true)
            {
                radioButton9.Checked = true;
            }
        }
        //*********************************************************
        private void radioButton2_CheckedChanged(object sender, EventArgs e)
        {
            if (radioButton2.Checked == true)
            {
                radioButton9.Checked = true;
            }
        }
        //*********************************************************
        private void radioButton3_CheckedChanged(object sender, EventArgs e)
        {
            if (radioButton3.Checked == true)
            {
                radioButton9.Checked = true;
            }
        }
        //*********************************************************
    }
}
