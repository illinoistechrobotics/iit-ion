using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using Microsoft.DirectX.DirectInput; 

namespace robotJoystickDriver
{
    public partial class Form1 : Form
    {
        Device joystickDevice;
        JoystickState state;

        // To make form moveable 
        private const int WM_NCHITTEST = 0x84;
        private const int HTCLIENT = 0x1;
        private const int HTCAPTION = 0x2;
      
        public Form1()
        {
            InitializeComponent();
            //toolTip1.SetToolTip(label5,
            //    "This program is provided for IIT Robotic Group");
        }

        // To make form moveable
        protected override void WndProc(ref Message m)
        {
            switch (m.Msg)
            {
                case WM_NCHITTEST:
                    base.WndProc(ref m);
                    if ((int)m.Result == HTCLIENT)
                        m.Result = (IntPtr)HTCAPTION;
                    return;
                // break;
            }
            base.WndProc(ref m);
        }

        private void Connect2Joystick()
        {
            richTextBox1.Text = "Settings:";
            try
            {
                // Find all the GameControl devices that are attached.
                DeviceList gameControllerList = Manager.GetDevices(
                    DeviceClass.GameControl,
                    EnumDevicesFlags.AttachedOnly);

                // check that we have at least one device.
                if (gameControllerList.Count > 0)
                {
                    timer1.Start(); // Read Joystick status by polling base on a timer_tick

                    // Move to the first device
                    gameControllerList.MoveNext();
                    DeviceInstance deviceInstance = (DeviceInstance)
                        gameControllerList.Current;

                    // create a device from this controller.
                    joystickDevice = new Device(deviceInstance.InstanceGuid);
                    joystickDevice.SetCooperativeLevel(this,
                        CooperativeLevelFlags.Background |
                        CooperativeLevelFlags.NonExclusive);


                    // Tell DirectX that this is a Joystick.
                    joystickDevice.SetDataFormat(DeviceDataFormat.Joystick);

                    // Finally, acquire the device.
                    joystickDevice.Acquire();

                    // Find the capabilities of the joystick
                    DeviceCaps cps = joystickDevice.Caps;

                    // number of Axes
                    richTextBox1.Text += ("\n Joystick Axes = " + cps.NumberAxes);

                    // number of Buttons
                    richTextBox1.Text += ("\n Joystick Buttons = " + cps.NumberButtons);

                    // number of PoV hats
                    richTextBox1.Text += ("\n Joystick PoV hats = "
                        + cps.NumberPointOfViews);
                }
                else
                {
                    // "There is no Joystics available!"
                    MessageBox.Show("There is no Joystics available!", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                }
            }
            catch (Exception err)
            {
                MessageBox.Show(err.Message);
            }
        }
        private void buttonJoystick_Click(object sender, EventArgs e)
        {
            Connect2Joystick();                                
        }

        private void Poll()
        {
            try
            {
                // poll the joystick
                joystickDevice.Poll();

                // update the joystick state field
                state = joystickDevice.CurrentJoystickState;
            }
            catch (Exception err)
            {
                // we probably lost connection to the joystick
                // was it unplugged or locked by another application?
                richTextBox1.Text += (err.Message);
            }
        }

        private void timesUp(object sender, EventArgs e)
        {
            Poll();
            richTextBox2.Text = "Test Window";
            int RightStickY = state.Rz;
            int RightStickX = state.Z;
            int LeftStickX = state.X;
            int LeftStickY = state.Y;
   
            // Display axes values
            RightStickYY.Text = RightStickY.ToString();
            RightStickXX.Text = RightStickX.ToString();
            LeftStickXX.Text = LeftStickX.ToString();
            LeftStickYY.Text = LeftStickY.ToString();

            // Check Buttons
            byte[] buttons = state.GetButtons();
            int i = 0;
            bool anyButtonPressed = false;
            foreach (byte but in buttons)
            {
                i++;
                if (but >= 128)
                {                   
                    LabelButton.ForeColor = Color.Red;
                    LabelButton.Text = "Button " + i + " pressed";
                    anyButtonPressed = true;
                }
            }
            if (anyButtonPressed == false)
            {
                LabelButton.ForeColor = Color.White;
                LabelButton.Text = "No buttons pressed";
            }
            // JsendCommandTest(); // temp (Testing purpose)

            // Send commands via serial (USB)
            if (USBport.IsOpen == true)//(buttonConnectSerial.Text == "Disconnect (USB Port)")
            // It means Serial is connected
            {
                JsendCommand();
            }
        }               

        private void JsendCommand()
        {            
            int RightStickY = state.Rz; //RYY
            int RightStickX = state.Z;
            int LeftStickX = state.X;
            int LeftStickY = state.Y;  //LYY
            
            byte val = 0;            
            if (LeftStickY <= 32768)
            {
                val = Convert.ToByte(60 + LeftStickY  * (185 - 60) / (32767));
            }
            else if (LeftStickY > 32768)
            {
                val = Convert.ToByte(100 + LeftStickY * (65) / (32768));
            }

            byte val2 = 0;
            if (RightStickY <= 32768)
            {
                val2 = Convert.ToByte(250 + RightStickY * (175 - 250) / (32767));
            }
            else if (RightStickY > 32768)
            {
                val2 = Convert.ToByte(280 + RightStickY * (60 - 175) / (32767));
            }
            // Provide appropriate Data to send (via USB)
            byte[] b = {val,val2,10};               
            USBport.Write(b, 0, 3);
            /*
            for (int j = 0; j < 4; j++)
            {
                USBport.Write(b, j, 1);
                //USBport.WriteLine("");
            }*/
            richTextBox3.Text = "\n" + "\t" + b[0] + "\t" + b[1];            
        }

        // THIS METHOD IS FOR TESTING PURPOSE
        /*
        private void JsendCommandTest()
        {
            int axisA = state.Rz;
            int axisB = state.Z;
            int axisC = state.X;
            int axisD = state.Y;

            byte val = 0;
            //byte g = 255;
            if (axisD <= 32768)
            {
                //val = Convert.ToByte(128 - (axisD / 256));
                val = Convert.ToByte(250 + axisD * (175 - 250) / (32767));
            }
            else if (axisD > 32768)
            {
               val = Convert.ToByte( 280 + axisD * ( 60- 175) / (32767)); 
            }            
            textBox1.Text = "" + Convert.ToString(val);
        }*/

        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            USBport.Close();
        }   

        private void serialPort1_DataReceived(object sender, System.IO.Ports.SerialDataReceivedEventArgs e)
        {
           // richTextBox2.Text = "";
            while (USBport.BytesToRead > 0)
            {
                int c = USBport.ReadByte();
              //  richTextBox2.AppendText(c.ToString());
            }            
        }


        private void ConnectSerial_Click(object sender, EventArgs e)
        {
                       
            if (USBport.IsOpen == false) //buttonConnectSerial.Text == "Connect (USB Port)"
            {
                // Set COM Port
                string str = comboBox1.GetItemText(comboBox1.SelectedItem);
                if (comboBox1.SelectedItem != null)
                {
                    USBport.PortName = str;
                }
                textBox1.Text = str;
                try
                {
                    USBport.Open();
                    buttonConnectSerial.Text = "Disconnect (USB Port)";
                }
                catch (Exception err)
                {
                    MessageBox.Show(err.Message);
                    //throw;
                }
            }
            else if ( USBport.IsOpen == true) //(buttonConnectSerial.Text == "Disconnect (USB Port)"
            {
                USBport.Close();
                buttonConnectSerial.Text = "Connect (USB Port)";
            }
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            comboBox1.SelectedIndex = 2; // set COM3 as the default value 
            Connect2Joystick();
        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            buttonConnectSerial.Select(); 
        }

        private void buttonClose_Click(object sender, EventArgs e)
        {
            this.Close(); // Close the form (application)
        }
    }
}