namespace Sample_MVC
{
    partial class View
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
            this.Connect_btn = new System.Windows.Forms.Button();
            this.Send_btn = new System.Windows.Forms.Button();
            this.Send_Box = new System.Windows.Forms.TextBox();
            this.Receive_btn = new System.Windows.Forms.Button();
            this.Msg = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // Connect_btn
            // 
            this.Connect_btn.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Connect_btn.Location = new System.Drawing.Point(160, 38);
            this.Connect_btn.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.Connect_btn.Name = "Connect_btn";
            this.Connect_btn.Size = new System.Drawing.Size(144, 50);
            this.Connect_btn.TabIndex = 0;
            this.Connect_btn.Text = "Connect";
            this.Connect_btn.UseVisualStyleBackColor = true;
            // 
            // Send_btn
            // 
            this.Send_btn.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Send_btn.Location = new System.Drawing.Point(37, 206);
            this.Send_btn.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.Send_btn.Name = "Send_btn";
            this.Send_btn.Size = new System.Drawing.Size(161, 49);
            this.Send_btn.TabIndex = 1;
            this.Send_btn.Text = "Send";
            this.Send_btn.UseVisualStyleBackColor = true;
            // 
            // Send_Box
            // 
            this.Send_Box.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Send_Box.Location = new System.Drawing.Point(37, 134);
            this.Send_Box.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.Send_Box.Name = "Send_Box";
            this.Send_Box.Size = new System.Drawing.Size(392, 26);
            this.Send_Box.TabIndex = 2;
            this.Send_Box.TextChanged += new System.EventHandler(this.Send_Box_TextChanged);
            // 
            // Receive_btn
            // 
            this.Receive_btn.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Receive_btn.Location = new System.Drawing.Point(269, 206);
            this.Receive_btn.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.Receive_btn.Name = "Receive_btn";
            this.Receive_btn.Size = new System.Drawing.Size(161, 48);
            this.Receive_btn.TabIndex = 3;
            this.Receive_btn.Text = "Receive";
            this.Receive_btn.UseVisualStyleBackColor = true;
            // 
            // Msg
            // 
            this.Msg.AutoSize = true;
            this.Msg.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Msg.Location = new System.Drawing.Point(53, 306);
            this.Msg.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.Msg.Name = "Msg";
            this.Msg.Size = new System.Drawing.Size(79, 20);
            this.Msg.TabIndex = 4;
            this.Msg.Text = "Lable Box";
            this.Msg.Click += new System.EventHandler(this.Msg_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 11F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.Location = new System.Drawing.Point(40, 106);
            this.label1.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(66, 18);
            this.label1.TabIndex = 4;
            this.label1.Text = "Text Box";
            // 
            // View
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(487, 390);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.Msg);
            this.Controls.Add(this.Receive_btn);
            this.Controls.Add(this.Send_Box);
            this.Controls.Add(this.Send_btn);
            this.Controls.Add(this.Connect_btn);
            this.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.Name = "View";
            this.Text = "MVC Example";
            this.Load += new System.EventHandler(this.View_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        
        private System.Windows.Forms.Button Connect_btn;
        private System.Windows.Forms.Button Send_btn;
        private System.Windows.Forms.TextBox Send_Box;
        private System.Windows.Forms.Button Receive_btn;
        private System.Windows.Forms.Label Msg;
        private System.Windows.Forms.Label label1;
    }
}

