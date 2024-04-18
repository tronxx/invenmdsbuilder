object Frame_datostabla: TFrame_datostabla
  Left = 0
  Top = 0
  Width = 402
  Height = 137
  TabOrder = 0
  object GroupBox1: TGroupBox
    Left = 8
    Top = 2
    Width = 385
    Height = 104
    Caption = 'Ingrese los Datos'
    TabOrder = 0
    object lbl_orden: TLabel
      Left = 35
      Top = 72
      Width = 77
      Height = 13
      Caption = 'Esta en En Uso:'
    end
    object Label1: TLabel
      Left = 23
      Top = 24
      Width = 89
      Height = 13
      Caption = 'Descripcion Tabla:'
    end
    object Label2: TLabel
      Left = 19
      Top = 48
      Width = 93
      Height = 13
      Caption = 'Fecha de Creacion:'
    end
    object edt_descri: TEdit
      Left = 116
      Top = 21
      Width = 250
      Height = 21
      CharCase = ecUpperCase
      MaxLength = 35
      TabOrder = 0
    end
    object date_fecini: TDateTimePicker
      Left = 116
      Top = 45
      Width = 100
      Height = 21
      CalAlignment = dtaLeft
      Date = 38982.3491966782
      Time = 38982.3491966782
      DateFormat = dfShort
      DateMode = dmComboBox
      Kind = dtkDate
      ParseInput = False
      TabOrder = 1
    end
    object cmb_uso: TComboBox
      Left = 116
      Top = 69
      Width = 73
      Height = 21
      ItemHeight = 13
      TabOrder = 2
      Text = 'cmb_uso'
      Items.Strings = (
        'S'
        'N')
    end
  end
end
