using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows.Forms;

/**
* @author Abdelnasser Ouda
*
*/

namespace Sample_MVC
{
    class Model
    {
        public void Connect_to_TCP_server()
        {
            MessageBox.Show("Pretend a successful connection\n\nThis message from the Model.");
        }

        public void Send_to_TCP_server(String msg)
        {
            MessageBox.Show("The text \"" + msg + "\" will be sent to TCP connection\n\nThis message from the Model");
        }

        public String Get_From_TCP_server()
        {
            
            MessageBox.Show("The Model received the message and will send it to the Controller to update the view.\n \nThis message from the Model");

            return ("This message came from the Model");
        }

    }
}
