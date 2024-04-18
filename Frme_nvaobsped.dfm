object Frame_nvaobsped: TFrame_nvaobsped
  Left = 0
  Top = 0
  Width = 683
  Height = 89
  TabOrder = 0
  object GroupBox1: TGroupBox
    Left = 5
    Top = 1
    Width = 672
    Height = 80
    Caption = 'Nueva Observacion:'
    TabOrder = 0
    object Label1: TLabel
      Left = 10
      Top = 25
      Width = 33
      Height = 13
      Caption = 'Fecha:'
    end
    object Label2: TLabel
      Left = 8
      Top = 52
      Width = 37
      Height = 13
      Caption = 'Observ:'
    end
    object dtFecha: TDateTimePicker
      Left = 45
      Top = 22
      Width = 89
      Height = 21
      CalAlignment = dtaLeft
      Date = 40815.4231369329
      Time = 40815.4231369329
      DateFormat = dfShort
      DateMode = dmComboBox
      Kind = dtkDate
      ParseInput = False
      TabOrder = 0
    end
    object edtObserva: TEdit
      Left = 46
      Top = 49
      Width = 611
      Height = 21
      CharCase = ecUpperCase
      MaxLength = 70
      TabOrder = 1
    end
  end
end
