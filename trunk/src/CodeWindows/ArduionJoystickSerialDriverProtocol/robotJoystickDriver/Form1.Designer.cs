namespace robotJoystickDriver
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.buttonJostickStart = new System.Windows.Forms.Button();
            this.timer1 = new System.Windows.Forms.Timer(this.components);
            this.RightStickYY = new System.Windows.Forms.Label();
            this.RightStickXX = new System.Windows.Forms.Label();
            this.LeftStickXX = new System.Windows.Forms.Label();
            this.LeftStickYY = new System.Windows.Forms.Label();
            this.USBport = new System.IO.Ports.SerialPort(this.components);
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.buttonConnectSerial = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label9 = new System.Windows.Forms.Label();
            this.label10 = new System.Windows.Forms.Label();
            this.comboBox1 = new System.Windows.Forms.ComboBox();
            this.buttonClose = new System.Windows.Forms.Button();
            this.label5 = new System.Windows.Forms.Label();
            this.LabelButton = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.toolTip1 = new System.Windows.Forms.ToolTip(this.components);
            this.richTextBox1 = new System.Windows.Forms.RichTextBox();
            this.richTextBox2 = new System.Windows.Forms.RichTextBox();
            this.richTextBox3 = new System.Windows.Forms.RichTextBox();
            this.SuspendLayout();
            // 
            // buttonJostickStart
            // 
            this.buttonJostickStart.BackColor = System.Drawing.Color.MidnightBlue;
            this.buttonJostickStart.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.buttonJostickStart.ForeColor = System.Drawing.SystemColors.ControlLightLight;
            this.buttonJostickStart.Location = new System.Drawing.Point(248, 47);
            this.buttonJostickStart.Name = "buttonJostickStart";
            this.buttonJostickStart.Size = new System.Drawing.Size(109, 23);
            this.buttonJostickStart.TabIndex = 0;
            this.buttonJostickStart.Text = "Start Joystick";
            this.buttonJostickStart.UseVisualStyleBackColor = false;
            this.buttonJostickStart.Click += new System.EventHandler(this.buttonJoystick_Click);
            // 
            // timer1
            // 
            this.timer1.Tick += new System.EventHandler(this.timesUp);
            // 
            // RightStickYY
            // 
            this.RightStickYY.AutoSize = true;
            this.RightStickYY.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.RightStickYY.ForeColor = System.Drawing.SystemColors.ControlLightLight;
            this.RightStickYY.Location = new System.Drawing.Point(433, 150);
            this.RightStickYY.Name = "RightStickYY";
            this.RightStickYY.Size = new System.Drawing.Size(101, 17);
            this.RightStickYY.TabIndex = 6;
            this.RightStickYY.Text = "Right Stick Y";
            // 
            // RightStickXX
            // 
            this.RightStickXX.AutoSize = true;
            this.RightStickXX.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.RightStickXX.ForeColor = System.Drawing.SystemColors.ControlLightLight;
            this.RightStickXX.Location = new System.Drawing.Point(433, 118);
            this.RightStickXX.Name = "RightStickXX";
            this.RightStickXX.Size = new System.Drawing.Size(101, 17);
            this.RightStickXX.TabIndex = 7;
            this.RightStickXX.Text = "Right Stick X";
            // 
            // LeftStickXX
            // 
            this.LeftStickXX.AutoSize = true;
            this.LeftStickXX.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.LeftStickXX.ForeColor = System.Drawing.SystemColors.ControlLightLight;
            this.LeftStickXX.Location = new System.Drawing.Point(266, 118);
            this.LeftStickXX.Name = "LeftStickXX";
            this.LeftStickXX.Size = new System.Drawing.Size(91, 17);
            this.LeftStickXX.TabIndex = 8;
            this.LeftStickXX.Text = "Left Stick X";
            // 
            // LeftStickYY
            // 
            this.LeftStickYY.AutoSize = true;
            this.LeftStickYY.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.LeftStickYY.ForeColor = System.Drawing.SystemColors.ControlLightLight;
            this.LeftStickYY.Location = new System.Drawing.Point(266, 150);
            this.LeftStickYY.Name = "LeftStickYY";
            this.LeftStickYY.Size = new System.Drawing.Size(91, 17);
            this.LeftStickYY.TabIndex = 9;
            this.LeftStickYY.Text = "Left Stick Y";
            // 
            // USBport
            // 
            this.USBport.PortName = "COM2";
            this.USBport.DataReceived += new System.IO.Ports.SerialDataReceivedEventHandler(this.serialPort1_DataReceived);
            // 
            // textBox1
            // 
            this.textBox1.Location = new System.Drawing.Point(46, 128);
            this.textBox1.Name = "textBox1";
            this.textBox1.ReadOnly = true;
            this.textBox1.Size = new System.Drawing.Size(100, 20);
            this.textBox1.TabIndex = 12;
            // 
            // buttonConnectSerial
            // 
            this.buttonConnectSerial.BackColor = System.Drawing.Color.MidnightBlue;
            this.buttonConnectSerial.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.buttonConnectSerial.ForeColor = System.Drawing.SystemColors.ControlLightLight;
            this.buttonConnectSerial.Location = new System.Drawing.Point(46, 83);
            this.buttonConnectSerial.Name = "buttonConnectSerial";
            this.buttonConnectSerial.Size = new System.Drawing.Size(130, 23);
            this.buttonConnectSerial.TabIndex = 13;
            this.buttonConnectSerial.Text = "Connect (USB Port)";
            this.buttonConnectSerial.UseVisualStyleBackColor = false;
            this.buttonConnectSerial.Click += new System.EventHandler(this.ConnectSerial_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.ForeColor = System.Drawing.SystemColors.ControlLightLight;
            this.label1.Location = new System.Drawing.Point(404, 89);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(86, 17);
            this.label1.TabIndex = 14;
            this.label1.Text = "Right Stick";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label2.ForeColor = System.Drawing.SystemColors.ControlLightLight;
            this.label2.Location = new System.Drawing.Point(243, 89);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(76, 17);
            this.label2.TabIndex = 15;
            this.label2.Text = "Left Stick";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label3.ForeColor = System.Drawing.SystemColors.ControlLightLight;
            this.label3.Location = new System.Drawing.Point(404, 150);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(23, 17);
            this.label3.TabIndex = 16;
            this.label3.Text = "Y:";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label4.ForeColor = System.Drawing.SystemColors.ControlLightLight;
            this.label4.Location = new System.Drawing.Point(243, 150);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(23, 17);
            this.label4.TabIndex = 17;
            this.label4.Text = "Y:";
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label9.ForeColor = System.Drawing.SystemColors.ControlLightLight;
            this.label9.Location = new System.Drawing.Point(404, 118);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(23, 17);
            this.label9.TabIndex = 18;
            this.label9.Text = "X:";
            // 
            // label10
            // 
            this.label10.AutoSize = true;
            this.label10.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label10.ForeColor = System.Drawing.SystemColors.ControlLightLight;
            this.label10.Location = new System.Drawing.Point(243, 118);
            this.label10.Name = "label10";
            this.label10.Size = new System.Drawing.Size(23, 17);
            this.label10.TabIndex = 19;
            this.label10.Text = "X:";
            // 
            // comboBox1
            // 
            this.comboBox1.BackColor = System.Drawing.Color.MidnightBlue;
            this.comboBox1.DisplayMember = "COM1";
            this.comboBox1.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.comboBox1.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.comboBox1.ForeColor = System.Drawing.Color.White;
            this.comboBox1.FormattingEnabled = true;
            this.comboBox1.Items.AddRange(new object[] {
            "COM1",
            "COM2",
            "COM3",
            "COM4",
            "COM5",
            "COM6",
            "COM7",
            "COM8",
            "COM9",
            "COM10"});
            this.comboBox1.Location = new System.Drawing.Point(46, 49);
            this.comboBox1.Name = "comboBox1";
            this.comboBox1.Size = new System.Drawing.Size(96, 21);
            this.comboBox1.TabIndex = 21;
            this.comboBox1.ValueMember = "COM1";
            this.comboBox1.SelectedIndexChanged += new System.EventHandler(this.comboBox1_SelectedIndexChanged);
            // 
            // buttonClose
            // 
            this.buttonClose.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("buttonClose.BackgroundImage")));
            this.buttonClose.Location = new System.Drawing.Point(740, 12);
            this.buttonClose.Name = "buttonClose";
            this.buttonClose.Size = new System.Drawing.Size(22, 23);
            this.buttonClose.TabIndex = 22;
            this.buttonClose.UseVisualStyleBackColor = true;
            this.buttonClose.Click += new System.EventHandler(this.buttonClose_Click);
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Font = new System.Drawing.Font("Microsoft Sans Serif", 7F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label5.ForeColor = System.Drawing.SystemColors.ControlLightLight;
            this.label5.Location = new System.Drawing.Point(12, 349);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(131, 13);
            this.label5.TabIndex = 23;
            this.label5.Text = "Designed by : Parham";
            this.toolTip1.SetToolTip(this.label5, "This program is provided for IIT Robotic Group");
            // 
            // LabelButton
            // 
            this.LabelButton.AutoSize = true;
            this.LabelButton.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.LabelButton.ForeColor = System.Drawing.SystemColors.ControlLightLight;
            this.LabelButton.Location = new System.Drawing.Point(305, 182);
            this.LabelButton.Name = "LabelButton";
            this.LabelButton.Size = new System.Drawing.Size(144, 17);
            this.LabelButton.TabIndex = 20;
            this.LabelButton.Text = "No Button Pressed";
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label6.ForeColor = System.Drawing.Color.Red;
            this.label6.Location = new System.Drawing.Point(12, 9);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(281, 17);
            this.label6.TabIndex = 24;
            this.label6.Text = "Joystic and USB Interface for Arduino";
            // 
            // richTextBox1
            // 
            this.richTextBox1.BackColor = System.Drawing.Color.Maroon;
            this.richTextBox1.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.richTextBox1.ForeColor = System.Drawing.SystemColors.Window;
            this.richTextBox1.Location = new System.Drawing.Point(565, 85);
            this.richTextBox1.Name = "richTextBox1";
            this.richTextBox1.ReadOnly = true;
            this.richTextBox1.Size = new System.Drawing.Size(147, 82);
            this.richTextBox1.TabIndex = 25;
            this.richTextBox1.Text = "Settings:";
            // 
            // richTextBox2
            // 
            this.richTextBox2.BackColor = System.Drawing.Color.Maroon;
            this.richTextBox2.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.richTextBox2.ForeColor = System.Drawing.SystemColors.Window;
            this.richTextBox2.ImeMode = System.Windows.Forms.ImeMode.NoControl;
            this.richTextBox2.Location = new System.Drawing.Point(46, 226);
            this.richTextBox2.Name = "richTextBox2";
            this.richTextBox2.ReadOnly = true;
            this.richTextBox2.Size = new System.Drawing.Size(147, 52);
            this.richTextBox2.TabIndex = 26;
            this.richTextBox2.Text = "Test Window";
            // 
            // richTextBox3
            // 
            this.richTextBox3.BackColor = System.Drawing.Color.Maroon;
            this.richTextBox3.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.richTextBox3.ForeColor = System.Drawing.SystemColors.Window;
            this.richTextBox3.Location = new System.Drawing.Point(287, 226);
            this.richTextBox3.Name = "richTextBox3";
            this.richTextBox3.ReadOnly = true;
            this.richTextBox3.Size = new System.Drawing.Size(179, 52);
            this.richTextBox3.TabIndex = 27;
            this.richTextBox3.Text = "Watch Window";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.Black;
            this.ClientSize = new System.Drawing.Size(774, 375);
            this.ControlBox = false;
            this.Controls.Add(this.richTextBox3);
            this.Controls.Add(this.richTextBox2);
            this.Controls.Add(this.richTextBox1);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.buttonClose);
            this.Controls.Add(this.comboBox1);
            this.Controls.Add(this.LabelButton);
            this.Controls.Add(this.label10);
            this.Controls.Add(this.label9);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.buttonConnectSerial);
            this.Controls.Add(this.textBox1);
            this.Controls.Add(this.LeftStickYY);
            this.Controls.Add(this.LeftStickXX);
            this.Controls.Add(this.RightStickXX);
            this.Controls.Add(this.RightStickYY);
            this.Controls.Add(this.buttonJostickStart);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None;
            this.MaximumSize = new System.Drawing.Size(774, 375);
            this.Name = "Form1";
            this.Opacity = 0.87;
            this.ShowIcon = false;
            this.Text = "Arduino ( Serial + Joystick )";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button buttonJostickStart;
        private System.Windows.Forms.Timer timer1;
        private System.Windows.Forms.Label RightStickYY;
        private System.Windows.Forms.Label RightStickXX;
        private System.Windows.Forms.Label LeftStickXX;
        private System.Windows.Forms.Label LeftStickYY;
        private System.IO.Ports.SerialPort USBport;
        private System.Windows.Forms.TextBox textBox1;
        private System.Windows.Forms.Button buttonConnectSerial;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.Label label10;
        private System.Windows.Forms.ComboBox comboBox1;
        private System.Windows.Forms.Button buttonClose;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label LabelButton;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.ToolTip toolTip1;
        private System.Windows.Forms.RichTextBox richTextBox1;
        private System.Windows.Forms.RichTextBox richTextBox2;
        private System.Windows.Forms.RichTextBox richTextBox3;
    }
}

